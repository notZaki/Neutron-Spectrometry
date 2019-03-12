#ifndef CUSTOM_CLASSES_H
#define CUSTOM_CLASSES_H

#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class UnfoldingSettings {
    public:
        double norm; 
        double error; 
        double f_factor; 
        int cutoff; 
        int num_poisson_samples; 
        std::string meas_units; 
        // MAP specific
        double beta; 
        std::string prior;
        //MLEM-STOP specific
        int cps_crossover;
        // Optimize specific
        int min_num_iterations;
        int max_num_iterations;
        int iteration_increment;
        double min_beta;
        double max_beta;
        std::string parameter_of_interest;
        std::string algorithm;
        std::string trend_type;
        std::string path_output_spectra;
        int generate_report;
        std::string path_report;
        int generate_figure;
        std::string path_figure;
        std::string auto_output_path;
        int derivatives;
        std::string measurements_path;
        std::string input_spectrum_path;
        std::string energy_bins_path;
        std::string system_response_path;
        std::string icrp_factors_path;
        std::string ref_spectrum_path;

        UnfoldingSettings(); 

        void set_setting(std::string,std::string);

        void set_norm(double);
        void set_error(double);
        void set_f_factor(double);
        void set_cutoff(int);
        void set_num_poisson_samples(int);
        void set_meas_units(std::string);
        void set_beta(double);
        void set_prior(std::string);
        void set_cps_crossover(int);
        void set_min_num_iterations(int);
        void set_max_num_iterations(int);
        void set_iteration_increment(int);
        void set_min_beta(double);
        void set_max_beta(double);
        void set_parameter_of_interest(std::string);
        void set_algorithm(std::string);
        void set_trend_type(std::string);
        void set_path_output_spectra(std::string);
        void set_generate_report(int);
        void set_path_report(std::string);
        void set_generate_figure(int);
        void set_path_figure(std::string);
        void set_auto_output_path(std::string);
        void set_derivatives(int);
        void set_measurements_path(std::string);
        void set_input_spectrum_path(std::string);
        void set_energy_bins_path(std::string);
        void set_system_response_path(std::string);
        void set_icrp_factors_path(std::string);
        void set_ref_spectrum_path(std::string);
};


class UnfoldingReport {
    public:
        const std::string HEADER_DIVIDE = 
            "************************************************************************************************************************\n";
        const std::string SECTION_DIVIDE = 
            "\n========================================================================================================================\n\n";
        const std::string COLSTRING = 
            "--------------------";

        const int sw = 30; // settings column width
        const int cw = 20; // data column width
        const int rw = 9; // NNS response column width

        std::string path;
        std::string irradiation_conditions;
        std::vector<std::string> input_files;
        std::vector<std::string> input_file_flags;

        int cutoff;
        double error;
        double norm;
        double f_factor;
        int num_measurements;
        int num_bins;
        int num_poisson_samples;
        std::string git_commit;

        std::vector<double> measurements; // measurements_report
        double dose_mu;
        double doserate_mu;
        int duration;
        std::string meas_units;

        std::vector<double> initial_spectrum;
        std::vector<double> energy_bins;
        std::vector<std::vector<double>> nns_response;
        std::vector<double> icrp_factors;

        std::vector<double> spectrum;
        std::vector<double> spectrum_uncertainty;
        int num_iterations;
        std::vector<double> mlem_ratio;
        double dose;
        double s_dose;
        double total_flux;
        double total_flux_uncertainty;
        double avg_energy;
        double avg_energy_uncertainty;

        //MAP
        double beta;
        std::string algorithm;

        // MLEM-STOP
        int cps_crossover;
        double j_threshold;
        double j_final;

        UnfoldingReport(); 

        void prepare_report();
        void report_header(std::ofstream&);
        void report_settings(std::ofstream&);
        void report_measurement_info(std::ofstream&);
        void report_inputs(std::ofstream&);
        void report_mlem_info(std::ofstream&);
        void report_results(std::ofstream&);

        void set_path(std::string);
        void set_irradiation_conditions(std::string);
        void set_input_files(std::vector<std::string>&);
        void set_input_file_flags(std::vector<std::string>&);

        void set_cutoff(int);
        void set_error(double);
        void set_norm(double);
        void set_f_factor(double);
        void set_num_measurements(int);
        void set_num_bins(int);
        void set_num_poisson_samples(int);
        void set_git_commit(std::string);

        void set_measurements(std::vector<double>&);
        void set_dose_mu(double);
        void set_doserate_mu(double);
        void set_duration(int);
        void set_meas_units(std::string);

        void set_initial_spectrum(std::vector<double>&);
        void set_energy_bins(std::vector<double>&);
        void set_nns_response(std::vector<std::vector<double>>&);
        void set_icrp_factors(std::vector<double>&);

        void set_spectrum(std::vector<double>&);
        void set_spectrum_uncertainty(std::vector<double>&);
        void set_num_iterations(int);
        void set_mlem_ratio(std::vector<double>&);
        void set_dose(double);
        void set_s_dose(double);
        void set_total_flux(double);
        void set_total_flux_uncertainty(double);
        void set_avg_energy(double);
        void set_avg_energy_uncertainty(double);

        void set_algorithm(std::string);

        void set_cps_crossover(int);
        void set_j_threshold(double);
        void set_j_final(double);
};


class SpectraSettings {
    public:
        std::string input_filename;
        std::string input_dir;
        std::string output_filename;
        std::string output_dir;
        std::string title;
        std::string x_label;
        std::string y_label;
        double y_min;
        double y_max;
        int x_res;
        int y_res;
        int y_num_divs;
        std::vector<std::string> legend_entries;
        std::vector<std::string> color_series;
        std::vector<std::string> color_error;
        int grayscale;
        std::vector<int> show_error;
        std::string error_style;
        int rows_per_spectrum;
        std::vector<int> line_style;
        std::vector<int> line_width;
        int border_width;
        int legend;
        std::vector<float> legend_coords;
        int textbox;
        std::vector<float> textbox_coords;
        std::vector<std::string> textbox_text;
        int plot_per_mu;
        std::vector<int> number_mu;
        std::vector<int> duration;
        int normalize;

        SpectraSettings();

        void set_setting(std::string,std::string);

        void set_input_filename(std::string);
        void set_input_dir(std::string);
        void set_output_filename(std::string);
        void set_output_dir(std::string);
        void set_title(std::string);
        void set_x_label(std::string);
        void set_y_label(std::string);
        void set_y_min(std::string);
        void set_y_max(std::string);
        void set_x_res(std::string);
        void set_y_res(std::string);
        void set_y_num_divs(std::string);
        void set_legend_entries(std::string);
        void set_color_series(std::string);
        void set_color_error(std::string);
        void set_grayscale(std::string);
        void set_show_error(std::string);
        void set_error_style(std::string);
        void set_rows_per_spectrum(std::string);
        void set_line_style(std::string);
        void set_line_width(std::string);
        void set_border_width(std::string);
        void set_legend(std::string);
        void set_legend_coords(std::string);
        void set_textbox(std::string);
        void set_textbox_coords(std::string);
        void set_textbox_text(std::string);
        void set_plot_per_mu(std::string);
        void set_number_mu(std::string);
        void set_duration(std::string);
        void set_normalize(std::string);
};

class PlotSettings {
    public:
        std::string input_filename;
        std::string input_dir;
        std::string output_filename;
        std::string output_dir;
        std::string title;
        std::string x_label;
        std::string y_label;
        double y_min;
        double y_max;
        double x_min;
        double x_max;
        int x_res;
        int y_res;
        int x_num_divs;
        int y_num_divs;
        int x_log;
        int y_log;
        int x_grid;
        int y_grid;
        std::vector<std::string> legend_entries;
        std::vector<std::string> color_series;
        int grayscale;
        // std::vector<std::string> color_error;
        // std::vector<int> show_error;
        std::vector<int> line_style;
        std::vector<int> line_width;
        int border_width;
        int legend;
        std::vector<float> legend_coords;
        int textbox;
        std::vector<float> textbox_coords;
        std::vector<std::string> textbox_text;

        std::vector<std::string> plot_type;
        int legend_border_size;
        double legend_text_size;
        std::vector<int> marker_style;
        std::vector<int> marker_size;
        double margin_left;
        double margin_right;
        double margin_top;
        double margin_bottom;
        double x_label_offset;
        double y_label_offset;

        PlotSettings(); 

        void set_setting(std::string,std::string);

        void set_input_filename(std::string);
        void set_input_dir(std::string);
        void set_output_filename(std::string);
        void set_output_dir(std::string);
        void set_title(std::string);
        void set_x_label(std::string);
        void set_y_label(std::string);
        void set_y_min(std::string);
        void set_y_max(std::string);
        void set_x_min(std::string);
        void set_x_max(std::string);
        void set_x_res(std::string);
        void set_y_res(std::string);
        void set_x_log(std::string);
        void set_y_log(std::string);
        void set_x_grid(std::string);
        void set_y_grid(std::string);
        void set_x_num_divs(std::string);
        void set_y_num_divs(std::string);
        void set_legend_entries(std::string);
        void set_color_series(std::string);
        void set_grayscale(std::string);
        // void set_color_error(std::string);
        // void set_show_error(std::string);
        void set_line_style(std::string);
        void set_line_width(std::string);
        void set_border_width(std::string);
        void set_legend(std::string);
        void set_legend_coords(std::string);
        void set_textbox(std::string);
        void set_textbox_coords(std::string);
        void set_textbox_text(std::string);

        void set_plot_type(std::string);
        void set_legend_border_size(std::string);
        void set_legend_text_size(std::string);
        void set_marker_style(std::string);
        void set_marker_size(std::string);
        void set_margin_left(std::string);
        void set_margin_right(std::string);
        void set_margin_top(std::string);
        void set_margin_bottom(std::string);
        void set_x_label_offset(std::string);
        void set_y_label_offset(std::string);
};

class SurfaceSettings {
    public:
        std::string input_filename;
        std::string input_dir;
        std::string output_filename;
        std::string output_dir;
        std::string title;
        std::string x_label;
        std::string y_label;
        std::string z_label;
        double y_min;
        double y_max;
        int x_min;
        int x_max;
        double z_min;
        double z_max;
        int x_res;
        int y_res;
        int x_num_divs;
        int z_num_divs;
        int color_palette;
        int num_color_bins;
        int border_width;

        SurfaceSettings(); 

        void set_setting(std::string,std::string);

        void set_input_filename(std::string);
        void set_input_dir(std::string);
        void set_output_filename(std::string);
        void set_output_dir(std::string);
        void set_title(std::string);
        void set_x_label(std::string);
        void set_y_label(std::string);
        void set_z_label(std::string);
        void set_y_min(std::string);
        void set_y_max(std::string);
        void set_x_min(std::string);
        void set_x_max(std::string);
        void set_z_min(std::string);
        void set_z_max(std::string);
        void set_x_res(std::string);
        void set_y_res(std::string);
        void set_x_num_divs(std::string);
        void set_z_num_divs(std::string);
        void set_color_palette(std::string);
        void set_num_color_bins(std::string);
        void set_border_width(std::string);
};

#endif