/**
 *@brief writes the given result to the fixed file
 *@param const char* the message to be written
 *@return void
 */
void write_log (const char*);
/**
 *@brief Checks whether the changment from previus value to current value is
 allowed.
 *@param int previus value
 *@param int current value
 *@return bool
 */
bool check_change(int , int );
/**
 *@brief Walks trough the given array, shots at every unit and checks the result.
 *@param int** sea Pointer to a two dimmensional array
 *@param bool repetition true , when all units are already shot.
 *@return bool true, if the test is passed, false otherwise.
 */
bool shot_test (int**, bool = false);
/**
 *@brief Walks trough the given array, changes every unit to 6 or 8.
 *@param int** sea Pointer to a two dimmensional array
 *@return void
 */
void prepare_for_repetition(int**);
