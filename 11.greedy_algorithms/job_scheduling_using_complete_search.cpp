/******************************************************************************
 * author: akhil
 * job sequencing algorithm for jobs with assosiated deadlines and profits.
*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm> // for begin() and end().
#include <numeric> // for accumulate.
using namespace std;

struct job{
    int job_id;
    int deadline;
    int profit;
};

int max_profit=0;
int job_size=0;
vector<job> ordered_jobs;

// checks if a subset is a valid order for jobs.
bool is_valid_subset(vector<job> ordered_jobs)
{
	int size= ordered_jobs.size();
	for(int i=0; i<size; i++)
	{
		if(ordered_jobs[i].deadline<=i)
		{
			return false;
		}
	}
	return true;
}

void complete_search(vector<job> job_list, int index, int size)
{
	if(index==size)
	{
		if(is_valid_subset(ordered_jobs))
		{
			int profit= accumulate(begin(ordered_jobs), end(ordered_jobs), 0, []( int total, job j)->int{return total+=j.profit;});
			if(profit>max_profit)
			{
				max_profit=profit;
				job_size= ordered_jobs.size();
			}
		}

	}
	else
	{
		ordered_jobs.push_back(job_list[index]);
		complete_search(job_list, index+1, size );
		ordered_jobs.pop_back();
		complete_search(job_list, index+1, size );

	}
}

int main(void)
{
    int test_cases, num_of_jobs;
    vector<job> job_list;
    // buffer to store the job_ids.
    job buffer;
    
    cin>>test_cases;
while(test_cases--)
    {
    cin>>num_of_jobs;
    job_list.clear(); // deleting all the elements of the vector.
    // get the job details for the input.
    for(int i=0; i<num_of_jobs; i++)
    {
        
        cin>>buffer.job_id;
        cin>>buffer.deadline;
        cin>>buffer.profit;
        job_list.push_back(buffer);
    }
    int s= job_list.size();
    complete_search(job_list,0, s);
    cout<<job_size<<" "<<max_profit<<endl;
    }
    
    return 0;
}
