# Instructions for `plot_spectra.exe`

This application is used to plot one or more neutron fluence spectra on a single set of axes.

## Table of Contents

* [Input files](#input-files)
    * [CSV spectra file](#csv-spectra-file)
    * [Settings file](#settings-file)
* [Output files](#output-files)
    * [Figure file](#figure-file)
* [Settings](#settings)

## Input files

### CSV spectra file
* This file contains the neutron fluence spectra to be plotted.
* The accepted format is the same as the CSV output file of [`unfold_spectrum.exe`](instructions_unfold_spectrum.md)
    * The first line contains the energy bins [MeV]
    * The second line contains a fluence spectrum [neutrons cm<sup>-2</sup> s<sup>-1</sup>]
    * The third line contains the lower uncertainty.
    * The fourth line contains the upper uncertainty.
    * Subsequent lines add more spectra and their uncertainties.
* File is set via the `path_input_data` setting.

### Settings file
* This file contains all of the user-configurable settings for the application.
* Input file: `input/plot_spectra.cfg`
* The description of each setting is provided in the [Settings Table below](#settings).
* Default values are indicated where applicable.
    * To use default values, **do not delete settings, simply leave the value blank**.

## Output files

### Figure file 
* This file contains the plotted output generated by the application.
* File is set via the `path_output_figure` setting.
    * Include the desired file output type (e.g. `output/output_spectra.png` vs. `output/output_spectra.eps`, etc.)

## Settings:

| Name | Default value | description |
| ---- | ------------- | ----------- |
| border_width | `5` | Line width of plot border. |
| color_error | `#333333,#E79A9F,#6B8EF0,`<br>`#69CF77,#ad4ace,#e2a56f,`<br>`#69c6db` | Specify color of uncertainy region around spectra using comma-delimited list of HEX color values. Pattern repeats if there are more series than colors specified. |
| color_series | `#000000,#C63822,#607FD5,`<br>`#55A961,#75298e,#ce884a,`<br>`#33889b` | Specify color of spectra using comma-delimited list of HEX color values. Pattern repeats if there are more series than colors specified. |
| duration | N/A | If `plot_per_mu=1`, use this to specify the duration of exposure per moderator configuration. |
| error_fill_style | `3001` | The fill pattern to use in the uncertainty region. See [Root docs](https://root.cern.ch/doc/master/classTAttFill.html#F2). |
| error_style | `E2` | The visual style with which uncertainties are displayed. See [Root docs](https://root.cern.ch/doc/master/classTHistPainter.html#HP01b). |
| font_size | `1` | Scaling factor applied to all text in the figure. e.g. font_size = 2 makes text twice as large. Use element-specific settings when necessary. |
| font_size_axis_labels | `1` | Scaling factor applied to axis labels (titles). e.g. font_size = 2 makes text twice as large. |
| font_size_axis_tick_labels | `1` | Scaling factor applied to axis tick labels. e.g. font_size = 2 makes text twice as large. |
| font_size_legend | `1` | Scaling factor applied to legend entries. e.g. font_size = 2 makes text twice as large. |
| font_size_textbox | `1` | Scaling factor applied to the textbox. e.g. font_size = 2 makes text twice as large. |
| font_size_title | `1` | Scaling factor applied to the plot title. e.g. font_size = 2 makes text twice as large. |
| grayscale | `0` | If `grayscale=0`: plot in color. If `grayscale=1`: plot in grayscale. |
| legend | `1` | If `legend=1`: show legend. If `legend=0`: no legend. |
| legend_coords | `0.15,0.75,0.365,0.85` | Comma-delimited coordinates of the legend (format: lower x, lower y, upper x, upper y). Rule of thumb: add 0.05 between upper and lower y for each data series. |
| legend_entries | row headers in [input file](#csv-spectra-file) | Comma-delimited spectra names. e.g: spectrum 1,spectrum 2,spectrum 3 |
| line_style | `1` | Comma-delimited list of spectra line styles. See [Root docs](https://root.cern.ch/doc/master/classTAttLine.html#L3). If only a single value, apply to all spectra. |
| line_width | `5` | Comma-delimited list of spectra line widths. See [Root docs](https://root.cern.ch/doc/master/classTAttLine.html#L2). If only a single value, apply to all spectra. |
| margin_bottom | `0.1` | Whitespace margin to add to bottom of plot area, as a fractional percent of the canvas. |
| margin_left | `0.1` | Whitespace margin to add to left of plot area, as a fractional percent of the canvas. |
| margin_right | `0.1` | Whitespace margin to add to right of plot area, as a fractional percent of the canvas. |
| margin_top | `0.1` | Whitespace margin to add to top of plot area, as a fractional percent of the canvas. |
| normalize | `0` | If `normalize=0`: plot absolute spectral values. If `normalize=1`: plot spectra normalized to max value of 1. |
| number_mu | N/A | If `plot_per_mu=1`, use this to specify the # of MU delivered per moderator configuration. |
| path_input_data | `output/output_spectra.csv` | Pathname to [input CSV spectra file](#csv-spectra-file). |
| path_output_figure | `output/output_spectra.png` | Pathname to [ouput figure file](#figure-file). |
| plot_per_mu | `0` | If `plot_per_mu=0`: plot spectra in default units. If `plot_per_mu=1`: plot spectra per MU. |
| rows_per_spectrum | `3` | Number of rows attributed to a single spectrum and its uncertainties in [input CSV spectra file](#csv-spectra-file). |
| show_error | `1` | Comma-delimited list of 1s or 0s indicating whether uncertainty should be displayed for each spectrum. If only a single value, apply to all spectra. |
| textbox | `0` | If `textbox=1`: include a textbox. If `textbox=0`: no textbox. |
| textbox_coords | `0.15,0.4,0.4,0.6` | Comma-delimited coordinates of the textbox (format: lower x, lower y, upper x, upper y). |
| textbox_text | N/A | Comma-delimited text to include in text box. Commas delineate new lines. |
| title | N/A | Title of the plot. |
| x_label | `Energy (MeV)` | X-axis label. |
| x_label_offset | `1.4` | Double value to shift the x-axis label up or down. Changing by 0.1 adjusts position by 10 percent |
| x_max | max energy in [input file](#csv-spectra-file) | Max x-axis value. |
| x_min | min energy in [input file](#csv-spectra-file) | Min x-axis value. |
| x_res | `3200` | Horizontal resolution (dimension). Only applicable to rasterized image formats (e.g. PNG not EPS). |
| y_digits_max | `3` |  Max number of digits allowed on the y axis labels before scientific notation is used. |
| y_label | `Fluence (n #upoint cm^{-2} s^{-1})` | Y-axis label |
| y_label_offset | `1.4` | Double value to shift the y-axis label left or right. Changing by 0.1 adjusts position by 10 percent |
| y_max | 1.25x max spectral value in [input file](#csv-spectra-file) | Max y-axis value. |
| y_min | `0` | Min y-axis value. |
| y_num_divs | N/A | 3 digit number that specifies number of major and minor divisions (tick marks). See [Root docs](https://root.cern.ch/doc/master/classTAttAxis.html#ae3067b6d4218970d09418291cbd84084). |
| y_res | `2400` | Vertical resolution (dimension). Only applicable to rasterized image formats (e.g. PNG not EPS). |
