#include "../include/utils.h"

/* save buffer into file */
void
save_data (char *filename, char *buffer)
{
  if (filename == NULL)
    fprintf (stdout, "%s", buffer);
  else
    {
      FILE *file = fopen (filename, "w");
      fprintf (file, "%s", buffer);
      fclose (file);
    }
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

/* convert number into Kio or Mio */
double
convertion (double number)
{
  return (number > (1 << 20)) ? number / 1024.0 / 1024.0 : number / 1024.0;
}

/* save header of benchmark measure in buffer */
void
print_header_benchmark (char *buffer, long _matrix_size)
{
  sprintf (
      buffer, "%s %20s; %13s; %13s; %13s; %13s; %13s; %9s; %13s; %13s; %16s\n",
      buffer, "title", (_matrix_size > (1 << 20)) ? "buf (MiB)" : "buf (KiB)",
      "min (s)", "max (s)", "median (s)", "mean (s)", "dev %", "MiB/s",
      "Cycles", "Cycles/m-element");
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
  double _matrix_size = data->matrice_size;
  double _data_size = data->type;
  double _repetition = data->repetition;
  uint64_t _rc = data->RC[16];

  double _stddevp = (_stddev * 100.0) / _mean;
  double _rc_elem = _rc / _matrix_size;
  double _bw = ((double)_matrix_size / (1024.0 * 1024)) / _mean;

  sprintf (buffer,
           "%s %20s; %13.3lf; %13.3e; %13.3e; %13.3e; %13.3e; %9.3lf; "
           "%13.3lf; %13.3lu; %16.3lf \n",
           buffer, title, convertion (_matrix_size * _data_size), _min, _max,
           _median, _mean, _stddevp, _bw, _rc, _rc_elem);
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

  sprintf (buffer, "%s %25s; %13le; %13le; %13le; %13le\n", buffer, title,
           _accuracy, _rms, _forward_err, _backward_err);
}
