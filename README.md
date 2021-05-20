# Maze Generator

![](res/screenshots/MazeGenerator.png)

background image credits: <a href="http://www.freepik.com">Designed by 0melapics / Freepik</a>

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
  </ol>
</details>


## About The Project

[![Product Name Screen Shot][product-screenshot]](https://example.com)

# TODO

### Built With

* C++
* SFML

## Getting Started

To get a local copy up and running follow these simple example steps.

* Dowload the source code and run 'make' in the project directory. 
* Launch the executable located in the 'bin' directory: 'bin/main'

### Prerequisites

* Install [SFML](https://www.sfml-dev.org/) by following the instructions on their website.

## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

The Menu Screen: You can go to the menu at any time by clicking the 'M' key. It will pause the animation automatically.
To navigate the menu use the up, down arrow keys. To select an option click the 'RETURN' key (on mac os).

The Play option will simply start the animation on autoplay mode. You can disable autoplay constant in the ![](src/K/K.hpp) file. To update each frame manually use the 'N' key.

The Quit option will close the window.

![](res/screenshots/Menu.png)

Features:
* Maze generation: Maze generation is the primary feature of this application. The application can guarantee to always generate a solvable maze. The blue cells represent the path and the rest represent the walls of the maze. It uses a Union-Find algorithm to make sure there is a path from the start to end cell. 
*  Maze Solver: After the maze is generated, the application proceeds to solve the maze. It currently uses a breadth first search algorithm and colors the cells that are currently being explored.
*  Path Tracer: Finally the tracer comes into play, and traces the actual solution of the maze in a white color. 

The start and end cells, as well as other maze settings, can be changed in the settings menu. (TODO)

This screenshot shows the path tracer phase:

![](res/screenshots/PathSolver.png)

