#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITER 100

typedef struct
{
  float x;
  float y;
  int cluster;
} Point;

typedef struct
{
  float x;
  float y;
} Centroid;

float
distance (Point p1, Centroid p2)
{
  return sqrt ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void
initialize_centroids (Point points[], Centroid centroids[], int n_points,
                      int k)
{
  for (int i = 0; i < k; i++)
    {
      centroids[i].x = points[i].x;
      centroids[i].y = points[i].y;
    }
}

void
assign_clusters (Point points[], Centroid centroids[], int n_points, int k)
{
  for (int i = 0; i < n_points; i++)
    {
      float min_dist = distance (points[i], centroids[0]);
      int cluster = 0;
      for (int j = 1; j < k; j++)
        {
          float dist = distance (points[i], centroids[j]);
          if (dist < min_dist)
            {
              min_dist = dist;
              cluster = j;
            }
        }
      points[i].cluster = cluster;
    }
}

void
update_centroids (Point points[], Centroid centroids[], int n_points, int k)
{
  int count[k];
  for (int i = 0; i < k; i++)
    {
      centroids[i].x = 0;
      centroids[i].y = 0;
      count[i] = 0;
    }

  for (int i = 0; i < n_points; i++)
    {
      int cluster = points[i].cluster;
      centroids[cluster].x += points[i].x;
      centroids[cluster].y += points[i].y;
      count[cluster]++;
    }

  for (int i = 0; i < k; i++)
    {
      if (count[i] != 0)
        {
          centroids[i].x /= count[i];
          centroids[i].y /= count[i];
        }
    }
}

int
main ()
{
  int n_points, k;

  printf ("Enter the number of points: ");
  scanf ("%d", &n_points);
  Point points[n_points];

  // Seed the random number generator
  srand (time (0));

  // Generate random points
  for (int i = 0; i < n_points; i++)
    {
      points[i].x = (float)rand () / RAND_MAX;
      points[i].y = (float)rand () / RAND_MAX;
      points[i].cluster = -1;
    }

  printf ("Enter the number of clusters: ");
  scanf ("%d", &k);
  Centroid centroids[k];

  initialize_centroids (points, centroids, n_points, k);

  for (int iter = 0; iter < MAX_ITER; iter++)
    {
      assign_clusters (points, centroids, n_points, k);
      update_centroids (points, centroids, n_points, k);
    }

  FILE *fout = fopen ("kmeans_result.txt", "w");
  if (fout == NULL)
    {
      perror ("Error opening file");
      return 1;
    }

  // Print points with their clusters
  for (int i = 0; i < n_points; i++)
    {
      fprintf (fout, "%lf %lf %d\n", points[i].x, points[i].y,
               points[i].cluster);
    }

  // Print centroids
  for (int i = 0; i < k; i++)
    {
      fprintf (fout, "%lf %lf %d\n", centroids[i].x, centroids[i].y, k);
    }

  fclose (fout);
  printf ("K-means clustering result written to 'kmeans_result.txt'\n");

  return 0;
}
