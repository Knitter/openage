// Copyright 2024-2024 the openage authors. See copying.md for legal info.

#pragma once

#include "pathfinding/definitions.h"
#include "util/path.h"


namespace openage::path::tests {


/**
 * Show the functionality of the high-level pathfinder:
 *     - Grids
 *     - Sectors
 *     - Portals
 *
 * Visualizes the pathfinding results using our rendering backend.
 *
 * @param path Path to the project rootdir.
 */
void path_demo_1(const util::Path &path);


// Cost for the sectors in the grid
// taken from Figure 23.1 in "Crowd Pathfinding and Steering Using Flow Field Tiles"
const std::vector<std::vector<cost_t>> sectors_cost = {
	{
		// clang-format off
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1, 255, 255, 255, 255,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1, 255, 255, 255, 255,   1,   1,
        1,   1,   1, 255, 255, 255, 255, 255,   1,   1,
        1,   1, 255, 255, 255, 255, 255,   1,   1,   1,
        1,   1, 255,   1,   1,   1,   1,   1,   1,   1,
        1,   1, 255,   1,   1,   1,   1,   1,   1,   1,
		// clang-format on
	},
	{
		// clang-format off
        1,   1, 255, 255, 255, 255, 255, 255, 255, 255,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1, 255,   1,   1, 255,   1,   1,   1,
        1,   1,   1, 255,   1, 255, 255,   1,   1,   1,
        1,   1,   1, 255, 255, 255, 255, 255, 255, 255,
        1,   1,   1,   1, 255, 255, 255,   1,   1,   1,
        1,   1,   1,   1, 255, 255,   1,   1,   1,   1,
        1,   1,   1, 255,   1,   1,   1,   1,   1,   1,
		// clang-format on
	},
	{
		// clang-format off
      255, 255,   1,   1,   1,   1,   1, 255, 255, 255,
        1,   1,   1,   1,   1,   1,   1,   1, 255, 255,
        1,   1,   1,   1,   1,   1,   1,   1, 255, 255,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1, 255, 255, 255,   1,   1,   1,
        1,   1,   1,   1,   1, 255, 255, 255, 255, 255,
        1,   1,   1,   1, 255, 255, 255, 255, 255,   1,
        1,   1,   1,   1, 255,   1,   1,   1,   1,   1,
        1,   1,   1,   1, 255,   1,   1,   1,   1, 255,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
		// clang-format on
	},
	{
		// clang-format off
      255, 255,   1,   1,   1,   1,   1,   1,   1,   1,
      255, 255,   1,   1,   1,   1,   1,   1,   1,   1,
      255, 255,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1, 255,   1,   1,   1,   1,   1,   1,
        1,   1, 255, 255,   1,   1,   1,   1,   1,   1,
      255, 255, 255, 255,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
		// clang-format on
	},
	{
		// clang-format off
        1,   1, 255,   1,   1,   1,   1,   1,   1,   1,
        1,   1, 255,   1,   1,   1,   1,   1, 255,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1, 255,   1,   1,   1,   1,   1,
        1,   1,   1, 255, 255,   1,   1,   1,   1,   1,
        1,   1, 255,   1, 255,   1,   1,   1,   1,   1,
        1,   1,   1,   1, 255,   1,   1,   1,   1,   1,
        1,   1,   1,   1, 255, 255, 255, 255, 255, 255,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1, 255, 255, 255,
		// clang-format on
	},
	{
		// clang-format off
        1,   1,   1, 255,   1,   1,   1,   1,   1, 255,
        1,   1,   1, 255,   1, 255, 255, 255, 255, 255,
        1,   1,   1, 255,   1,   1,   1,   1, 255, 255,
        1,   1,   1, 255,   1,   1,   1,   1, 255, 255,
        1, 255, 255,   1,   1,   1,   1,   1, 255, 255,
        1,   1, 255,   1,   1, 255,   1,   1,   1,   1,
        1,   1, 255,   1,   1, 255,   1,   1,   1,   1,
      255, 255, 255, 255, 255, 255,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
      255,   1,   1,   1,   1,   1,   1,   1,   1,   1,
		// clang-format on
	},
	{
		// clang-format off
      255,   1,   1,   1,   1,   1,   1,   1,   1,   1,
      255,   1,   1,   1,   1,   1,   1,   1,   1,   1,
      255,   1,   1,   1,   1,   1,   1,   1, 255, 255,
      255,   1,   1,   1,   1,   1,   1,   1,   1,   1,
      255,   1,   1,   1,   1,   1, 255,   1,   1,   1,
      255,   1,   1,   1,   1,   1, 255,   1,   1,   1,
      255,   1,   1,   1,   1,   1, 255,   1,   1,   1,
      255,   1,   1,   1,   1,   1, 255, 255, 255, 255,
      255,   1,   1,   1, 255, 255, 255, 255, 255,   1,
      255,   1,   1,   1,   1,   1,   1,   1,   1,   1,
		// clang-format on
	},
	{
		// clang-format off
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
      255, 255,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1, 255, 255, 255, 255, 255,   1,   1,
        1,   1,   1,   1,   1,   1,   1, 255,   1,   1,
        1,   1,   1,   1,   1,   1,   1, 255,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
		// clang-format on
	},
	{
		// clang-format off
        1,   1, 255,   1,   1,   1,   1, 255, 255, 255,
        1,   1, 255,   1,   1,   1, 255, 255,   1,   1,
        1,   1,   1,   1,   1, 255, 255, 255,   1,   1,
        1,   1,   1,   1, 255,   1,   1,   1,   1,   1,
        1,   1,   1,   1, 255,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1, 255,
        1,   1,   1,   1,   1,   1,   1,   1, 255,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
		// clang-format on
	},
	{
		// clang-format off
      255,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1, 255,   1,   1,   1,   1,   1,   1,
        1,   1, 255, 255, 255, 255, 255, 255,   1,   1,
        1, 255, 255, 255,   1,   1,   1,   1,   1,   1,
      255, 255, 255, 255,   1,   1,   1,   1,   1,   1,
      255,   1,   1,   1,   1,   1,   1,   1,   1, 255,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
		// clang-format on
	},
	{
		// clang-format off
      255,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1, 255, 255, 255, 255, 255,   1,   1,
        1,   1, 255, 255,   1,   1,   1, 255,   1,   1,
        1, 255, 255,   1,   1,   1,   1,   1,   1,   1,
      255, 255,   1,   1,   1,   1,   1,   1,   1,   1,
      255, 255,   1,   1,   1, 255, 255, 255,   1,   1,
        1,   1,   1,   1,   1,   1, 255,   1,   1,   1,
        1,   1,   1, 255, 255, 255, 255,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
		// clang-format on
	},
	{
		// clang-format off
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
		// clang-format on
	}};

} // namespace openage::path::tests
