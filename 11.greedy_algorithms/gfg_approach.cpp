/******************************************************************************
 * author: akhil
 * Geeks for Geeks program to generate job scheduling with the maximum profit.
 * This is a standard GREEDY ALGORITHM implementation.
*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

struct job
{
  int job_id;
  int deadline;
  int profit;
};

// for printing all the jobs.
void
print_jobs (vector < job > &job_list)
{
for (auto itr:job_list)
    {
      cout << "job.job_id: " << itr.job_id << "\t";
      cout << "job.deadline: " << itr.deadline << "\t";
      cout << "job.profit: " << itr.profit << "\t";
      cout << endl;
    }
}

// this function pointer will be used in the sort STL function.
bool
sort_job (job j1, job j2)
{
  return j1.profit >= j2.profit;
}

// for adding profits.
int
add (int total, job j)
{
  total += j.profit;
  return total;
}

void
get_execution_order (vector < job > job_list)
{
  vector < job > ordered_jobs;	// the size of the ordered_jobs can't be more than the given jobs.:-)
  vector < bool > is_included (job_list.size (), false);
  int size = job_list.size ();
  int count = 0;
  // sort the job_list in the order of decreasing profit so that for the 
  // jobs with the same deadlines, one with higher profit is selected within 
  // the deadline if possible.
  sort (begin (job_list), end (job_list), sort_job);

  // for each job (order on the basis of there profits) we check if they need to be inserted in the 
  // ordered_jobs vector.
for (auto itr:job_list)
    {
      for (int j = min (itr.deadline, size) - 1; j >= 0; j--)
	{
	  // we insert the job in the last possible available slot.
	  if (!is_included[j])
	    {
	      count++;
	      ordered_jobs.push_back (itr);
	      is_included[j] = true;
	      break;
	    }

	}
    }

  // printing the size and total profit.
  cout << count << " " << accumulate (begin (ordered_jobs),
				      end (ordered_jobs), 0, add) << " ";
  cout << endl;
  print_jobs (ordered_jobs);
  ordered_jobs.clear ();
}

int
main (void)
{
  int test_cases, num_of_jobs;
  vector < job > job_list;
  // buffer to store the job_ids.
  job buffer;

  cin >> test_cases;
  for (int i = 0; i < test_cases; i++)
    {
      cin >> num_of_jobs;
      job_list.clear ();
      // get the job details for the input.
      for (int i = 0; i < num_of_jobs; i++)
	{

	  cin >> buffer.job_id;
	  cin >> buffer.deadline;
	  cin >> buffer.profit;
	  job_list.push_back (buffer);
	}
      get_execution_order (job_list);
    }

  return 0;
}

