#!/usr/bin/python3
'''Module that calculates the perimeter of an island in a grid.'''


def water_neighbors(grid, x, y):
    '''Returns the number of water neighbors a cell has in a grid.'''

    v = 0

    if x <= 0 or not grid[x - 1][y]:
        v += 1
    if y <= 0 or not grid[x][y - 1]:
        v += 1
    if y >= len(grid[i]) - 1 or not grid[x][y + 1]:
        v+= 1
    if x >= len(grid) - 1 or not grid[x + 1][y]:
        v += 1

    return v


def island_perimeter(grid):
    '''Returns the perimeter of the island in grid.'''

    _perimeter = 0
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y]:
                _perimeter += water_neighbors(grid, x, y)

    return _perimeter
