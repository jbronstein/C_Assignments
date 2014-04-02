#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int indexFrom;
	int indexTo;
} MapEntry;

typedef MapEntry * Map;

int permute(void *data, int nblobs, size_t szblob, Map map){
		int i, j;
		i = j = 0;	 	
		/*initialize the one void temp value to be correct size*/
		void* temp = (void*)malloc(sizeof(szblob));
		
		/*nested for loop with assumption that all indexFroms are unique */
		
		for (i = 0; i<nblobs;i++){
		
			/*memcpy to do the swap*/

			memcpy(temp, (data + map[i].indexTo), szblob);
			memcpy((data + map[i].indexTo), (data + map[i].indexFrom), szblob);
			memcpy((data + map[i].indexFrom), temp, szblob);
			
			/*have to check any future indexFroms*/
			for (j = i+1; j < nblobs; j++){
				if(map[j].indexFrom == map[i].indexTo){
					map[j].indexFrom = map[i].indexFrom;
				}
			}
		}
		return 0;
	}
