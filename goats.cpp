#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	int goats = 0;
	int maxCours = 0;
	
	scanf("%d %d",&goats,&maxCours);

	std::vector<int> weight(goats);
	// Input and sort goat array.
	for(int i=0;i<goats;++i){
		scanf("%d",&weight[i]);
	}
	std::sort(weight.begin(),weight.end());

	// Setting starting maximum capacity of the boat.
	int maxCapacity = weight[goats-1];

	// This flag is raised when we reach a solution.
	bool passed = 0;

	// Bool array that tells us if the i-th goat is on the boat.
	std::vector<bool> onTheBoat(goats,0);

	while(!passed){
		// Count the courses and a flag that checks wether the
		// boat has been filled.
		int courses = 0;
		bool filled = false;

		// Keep doing courses until all goats have been transported.
		int goatCount = goats;
		while(goatCount>0){
			// Set the capacity of the course.
			int tempCapacity=maxCapacity;

			// Fill the boat until we run out of capacity
			for(int i=goats-1;i>=0;--i){
				// If a goat isn't on the boat and there's room for it
				// on there, then we throw it on the boat and reduce
				// the goatCount.
				if(!onTheBoat[i] && tempCapacity-weight[i]>=0){
					tempCapacity-=weight[i];
					onTheBoat[i]=1;
					--goatCount;
				}
			}

			// At this point of the while(goatCount>0) iteration we
			// have made a full course. We count it and check wether
			// we have exceeded the count fo the allowed maximumCourses.
			++courses;
			if(courses>maxCours)
				break;
		}

		// At this point of the loop all goats have been transported.
		// If they are equal to the maximum allowed amount then we are done.
		if(courses<=maxCours){
			passed=1;
			continue;
		}

		// Nullify the "On The Boat" array and raise the capacity and 
		// try again with a bigger (by 1) boat.
		for(int i=0;i<goats;++i)
			onTheBoat[i]=0;
		++maxCapacity;
	}

	printf("%d\n",maxCapacity);
}