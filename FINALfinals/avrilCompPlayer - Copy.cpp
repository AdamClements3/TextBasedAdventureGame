	// isOkayMove takes in i,j,k, returns currentState[i][j][k]
	// putMove(i,j,k,playerNum) changes currentState[i][j][k] = playerNum
	//   with a check to make sure that the user hasn't played out of turn,
	//   attempted to access an out of bound location, or attempted to
	//   overwrite a non-empty location
	// putMoveP(i,j,k,playerNum) changes currentState but has no check 
	//   for problems (some of you need it for copies of the board, do NOT use on the
	//   regular game board)
	
int computer::makeMoveAA(TTTBoard3 *Board){
	int N = Board->N;
	static int *int_last_move = new int[3]{-1,-1,-1};
	//--------------first move---------------------------
	//if center point is empty, TAKE IT
	if(Board->isOkayMove(N/2,N/2,N/2)==-1){
		for(int int_element = 0; int_element < 3; int_element++){
			int_last_move[int_element] = N/2;
		}
		Board->putMove(int_last_move[0],int_last_move[1],int_last_move[2],getNumber());
		return 0;
	}
	
	//----------------happens after center point is taken--------------------------------
	
	//if you can win, then win!
	for(int int_x = 0; int_x < N; int_x++){
		for(int int_y = 0; int_y < N; int_y++){
			for(int int_z = 0; int_z < N; int_z++){
				if(Board->isOkayMove(int_x, int_y, int_z)==-1){
					if(Board->canWin(int_x, int_y, int_z, getNumber())){
						int_last_move[0] = int_x;
						int_last_move[1] = int_y;
						int_last_move[2] = int_z;
						Board->putMove(int_last_move[0],int_last_move[1],int_last_move[2],getNumber());
						return 0;
					}
				}
			}
		}
	}
	
	//if the human can win, block!
	for(int int_x = 0; int_x < N; int_x++){
		for(int int_y = 0; int_y < N; int_y++){
			for(int int_z = 0; int_z < N; int_z++){
				if(Board->isOkayMove(int_x, int_y, int_z)==-1){
					if(Board->canWin(int_x, int_y, int_z,getNumber())){
						int_last_move[0] = int_x;
						int_last_move[1] = int_y;
						int_last_move[2] = int_z;
						Board->putMove(int_last_move[0],int_last_move[1],int_last_move[2],getNumber());
						return 0;
					}
				}
			}
		}
	}
	
	//otherwise, just fill in first available spot
	for(int int_x = 0; int_x < N; int_x++){
		for(int int_y = 0; int_y < N; int_y++){
			for(int int_z = 0; int_z < N; int_z++){
				if(Board->isOkayMove(int_x, int_y, int_z)==-1){
					int_last_move[0] = int_x;
					int_last_move[1] = int_y;
					int_last_move[2] = int_z;
					Board->putMove(int_last_move[0],int_last_move[1],int_last_move[2],getNumber());
					return 0;
				}
			}
		}
	}
	return 0;
}