/*

This file is from Sysfex, another system info fetching tool

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#pragma once

#include <unordered_map>
#include <string>
#include <string_view>

class Config {

private:
  static constexpr std::string_view default_config = R"(# Comments start with '#'

# Gap between ASCII/image and information
gap = 5

# Path to ASCII
# This path may point to an image as well
# `viu` is required for image to work
ascii = <path-to-ascii>

# For if ASCII is image
# The number of cells occupied by the image in X axis
image_width = 36

# Print information beside ASCII
# If disabled, information will be printed below the ASCII
info_beside_ascii = 1

# Clear terminal window before executing Sysfex
clear_screen = 0
)";

  std::unordered_map<std::string, std::string> config = {
    {"ascii", ""},
    {"clear_screen", "0"},
    {"gap", "5" },
    {"image_width", "36" },
    {"info_beside_ascii", "1" }
  };

public:

  static Config *the();

  void init(const std::string_view dir);

  void set_property(const std::string_view key, const std::string_view value);

  void generate_config_file(const std::string_view path);

  std::string get_property(const std::string_view key);

};
