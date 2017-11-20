#ifndef PHYSICS_CALCULATIONS_H
#define PHYSICS_CALCULATIONS_H

#include <stdlib.h>
#include <fstream>
#include <vector>

std::vector<double> normalizeResponse(int num_bins, int num_measurements, std::vector<std::vector<double>>& system_response);
double poisson(double lambda);
int runMLEM(int cutoff, double error, int num_measurements, int num_bins, std::vector<double> &measurements, std::vector<double> &spectrum, std::vector<std::vector<double>>& nns_response, std::vector<double> &normalized_response, std::vector<double> &mlem_ratio);
int runMAP(std::vector<double> &energy_correction, double beta, int cutoff, double error, int num_measurements, int num_bins, std::vector<double> &measurements, std::vector<double> &spectrum, std::vector<std::vector<double>>& nns_response, std::vector<double> &normalized_response, std::vector<double> &mlem_ratio);
double calculateDose(int num_bins, std::vector<double> &spectrum, std::vector<double> &icrp_factors);
int calculateRMSD_vector(int num_samples, std::vector<double> &true_vector, std::vector<std::vector<double>> &sampled_vectors, std::vector<double> &rms_differences);
double calculateRMSD(int num_samples, double true_value, std::vector<double> &sample_vector);

#endif