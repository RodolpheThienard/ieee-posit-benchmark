#include "../../include/utils.h"

double
simulate_asset_price (double S0, double r, double sigma, double T)
{
  // Générer un nombre aléatoire selon une distribution normale
  double Z = ((double)rand () / RAND_MAX);
  double epsilon = sqrt (-2 * log (Z));
  double delta_t
      = T; // On suppose que le temps de simulation est égal à la maturité T

  // Simuler le prix de l'actif sous-jacent à l'échéance
  return S0
         * exp ((r - 0.5 * sigma * sigma) * delta_t
                + sigma * epsilon * sqrt (delta_t));
}

void
monte_carlo_option_pricing_fp64 (double *vector, int n)
{

  for (int k = 0; k < n; k++)
    {
      double option_price_sum = 0;
      double S0 = 100;              // Prix initial de l'actif sous-jacent
      double K = 110;               // Prix d'exercice de l'option
      double r = 0.05;              // Taux d'intérêt sans risque
      double sigma = 0.2;           // Volatilité de l'actif sous-jacent
      double T = 1.0;               // Durée jusqu'à l'échéance de l'option
      int num_simulations = 100000; // Nombre de simulations Monte Carlo
      for (int i = 0; i < num_simulations; i++)
        {
          double S_T = simulate_asset_price (S0, r, sigma, T);
          double payoff = fmax (0, S_T - K);
          option_price_sum += payoff;
        }

      vector[k] = (option_price_sum / num_simulations) * exp (-r * T);
    }
}

void
monte_carlo_option_pricing_fp32 (float *vector, int n)
{

  for (int k = 0; k < n; k++)
    {
      float option_price_sum = 0;
      float S0 = 100;               // Prix initial de l'actif sous-jacent
      float K = 110;                // Prix d'exercice de l'option
      float r = 0.05;               // Taux d'intérêt sans risque
      float sigma = 0.2;            // Volatilité de l'actif sous-jacent
      float T = 1.0;                // Durée jusqu'à l'échéance de l'option
      int num_simulations = 100000; // Nombre de simulations Monte Carlo
      for (int i = 0; i < num_simulations; i++)
        {
          float S_T = (float)simulate_asset_price (S0, r, sigma, T);
          float payoff = fmaxf (0, S_T - K);
          option_price_sum += payoff;
        }

      vector[k] = (option_price_sum / num_simulations) * exp (-r * T);
    }
}
