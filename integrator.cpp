#include <iostream>
#include <thread>
#include <future>
#include <mutex>
void display()
{

}


void integrate(float x2, float slope, float constant, float start, float end, std::promise<double> * promise)
{
	double area = 0;
	double step = 0.000000001;
	for(double x = start; x < end; x += step)
	{
		area += ((x2 * x * x) + (x * slope) + constant) * step;
	}

	promise->set_value(area);
}
int main()
{
	std::mutex iomutex;
	std::cout << std::thread::hardware_concurrency();
	std::promise<double> area[8];
	std::future<double> fArea[8];
	float x2 = 54;
	float x = 61;
	float constant = 100;
	float start = 0;
	float end = 50;

	std::thread t[8];
		
	int arraylength = 8;
	for(int i = 0; i < arraylength; i++)
	{
		t[i] = std::thread([&iomutex, i, x2, x, constant, start, end, &area]
						{
							std::lock_guard<std::mutex> iolock(iomutex);
							integrate(x2, x, constant, start *  (i/8), end * ((i+1)/8), &area[i]);
						});
	}
	double sum = 0;
	
	for(int i = 0; i < arraylength; i++)
	{
		std::thread *thread = &t[i];
		thread->join();
		std::cout << "THREAD " + i << std::endl;
		fArea[i] = area[i].get_future();
		sum += fArea[i].get();
	}
	std::cout << sum << std::endl;

	return 0;
}

