#include "../include/utils.h"

/* save buffer into file */
void
save_data (char *filename, char *buffer)
{
  if (filename == NULL)
    fprintf (stdout, "%s", buffer);
  else
    {
      FILE *file = fopen (filename, "wa");
      fprintf (file, "%s", buffer);
      fclose (file);
    }
  // clear buffer
  memset (buffer, 0, 1000);
}

/* process data stored in struct data
   compute mean, stddev, and sort samples, RC */
void
formatting_data (struct data *data)
{
  sort_double (data->samples);
  sort_uint64 (data->RC);
  data->mean = mean (data->samples);
  data->stddev = stddev (data->samples, data->mean);
}

/* save header of benchmark measure in buffer */
void
print_header_benchmark (char *buffer)
{
  sprintf (buffer,
           "%s %20s; %13s; %13s; %13s; %13s; %13s; %9s; %13s; %13s; %13s\n",
           buffer, "title", "buffer (KiB)", "min (s)", "max (s)", "median (s)",
           "mean (s)", "dev %", "MiB/s", "+- MiB/s", "Cycles");
}

/* add formated data into buffer */
void
print_data_benchmark (char *title, struct data *data, char *buffer)
{

  double _min = data->samples[0];
  double _max = data->samples[32];
  double _median = data->samples[16];
  double _mean = data->mean;
  double _stddev = data->stddev;
  double _matrix_size = data->matrice_size * data->type;
  double _repetition = data->repetition;
  long _rc = data->RC[16];

  double _stddevp = (_stddev * 100.0) / _mean;
  double _rc_elem = _rc / _matrix_size;
  double _bw = ((double)_matrix_size / (1024.0 * 1024)) / _mean;
  double _dev_bw = _stddevp * _bw / 100;

  sprintf (buffer,
           "%s %20s; %13.3lf; %13.3e; %13.3e; %13.3e; %13.3e; %9.3lf; "
           "%13.3lf; %13.3lf; %13.3lu\n",
           buffer, title, _matrix_size / 1024.0, _min, _max, _median, _mean,
           _stddevp, _bw, _dev_bw, _rc);
}

/* save header of accuracy measure in buffer */
void
print_header_accuracy (char *buffer)
{
  sprintf (buffer, "%s %25s; %13s; %13s; %13s; %13s\n", buffer, "title",
           "accuracy mean", "accuracy RMS", "forward error", "backward error");
}

/* add formated data into buffer */
void
print_data_accuracy (char *title, char *buffer, struct accuracy *accuracy)
{
  double _accuracy = accuracy->accuracy;
  double _rms = accuracy->RMS;
  double _forward_err = accuracy->forward_error;
  double _backward_err = accuracy->backward_error;

  sprintf (buffer, "%s %20s; %13le; %13le; %13le; %13le\n", buffer, title,
           _accuracy, _rms, _forward_err, _backward_err);
}

void
print_header_diff (char *buffer)
{
  sprintf (buffer,
           "%s %20s; %13s; %13s; %13s; %13s; %13s; %9s; %13s; %13s; "
           "%13s; %13s; %13s; %13s\n",
           buffer, "title", "buffer (KiB)", "min (s)", "max (s)", "median (s)",
           "mean (s)", "dev %", "MiB/s", "+- MiB/s", "Cycles", "accuracy mean",
           "accuracy RMS", "forward error");
}

#define PERCENT(a, b) (((a) / b))

void
print_diff_accuracy (char *title, char *buffer, struct bench *bench,
                     struct data *data)
{

  double _min = PERCENT (data->samples[0], bench->data->samples[0]);
  double _max = PERCENT (data->samples[32], bench->data->samples[32]);
  double _median = PERCENT (data->samples[16], bench->data->samples[16]);
  double _mean = PERCENT (data->mean, bench->data->mean);
  double _stddev = PERCENT (data->stddev, bench->data->stddev);
  double _matrix_size = data->matrice_size;
  double _data_size = data->type;
  double _repetition = data->repetition;
  long _rc = data->RC[16] - bench->data->RC[16];

  double _stddevp = (_stddev * 100.0) / _mean;
  double _bw_data = ((double)_matrix_size / (1024.0 * 1024)) / data->mean;
  double _bw_bench
      = ((double)_matrix_size / (1024.0 * 1024)) / bench->data->mean;
  double _bw = PERCENT (_bw_data, _bw_bench);

  double _accuracy = bench->accuracy->accuracy;
  double _rms = bench->accuracy->RMS;
  double _forward_err = bench->accuracy->forward_error;

  sprintf (buffer,
           "%s %20s; %13.3s; %12.3lfx; %12.3lfx; %12.3lfx; %12.3lfx; %9.3s; "
           "%12.3lfx; %13.3s; %13ld; %13le; %13le; %13le\n\n",
           buffer, title, "", _min, _max, _median, _mean, "", _bw, "", _rc,
           _accuracy, _rms, _forward_err);
}
