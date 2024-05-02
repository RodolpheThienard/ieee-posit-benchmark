extern int __RacEr_x;               //The X Cord inside a tile group
extern int __RacEr_y;               //The Y Cord inside a tile group
extern int __RacEr_id;              //The ID of a tile in tile group
extern int __RacEr_grp_org_x;       //The X Cord of the tile group origin
extern int __RacEr_grp_org_y;       //The Y Cord of the tile group origin
extern int __RacEr_grid_dim_x;	  //The X Dimensions of the grid of tile groups
extern int __RacEr_grid_dim_y;	  //The Y Dimensions of the grid of tile groups
extern int __RacEr_tile_group_id_x; //The X Cord of the tile group within the grid
extern int __RacEr_tile_group_id_y; //The Y Cord of the tile group within the grid
extern int __RacEr_tile_group_id;   //The flat ID of the tile group within the grid

//----------------------------------------------------------
//RacEr_x and RacEr_y is going to be deprecated.
//We define the RacEr_x/RacEr_y only for compatibility purpose
#define RacEr_x __RacEr_x
#define RacEr_y __RacEr_y
#define RacEr_id __RacEr_id

void RacEr_set_tile_x_y();
