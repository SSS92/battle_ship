int** create_sea();

void delete_sea(int**);

void show_sea(int**);

int put_horizontal(int**, int, int, int);

int put_vertical(int**, int, int, int);

bool is_out_of_sea(int, int, int);

bool is_not_around_of_ship(int, int, int, int, int); 

bool is_invalid_position(int**, int, int, int);

int kill_ship(int**, int, int);

int fill_sea(int**);

void put_ship(int**, int, int, int);

int generate_random_number(int, int);

void show_shot_result(int);

void insert_shot_coordinates(int&, int&);

void play(int**, int);

void reset_input_stream();
