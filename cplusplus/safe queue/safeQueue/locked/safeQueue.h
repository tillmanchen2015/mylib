#ifndef safeQueue_h__
#define safeQueue_h__

#include <queue>  
#include <mutex>  
#include <memory>  
#include <condition_variable>  
#include <atomic>

template<typename T>
class SafeQueue
{
public:
	SafeQueue(int size=99999999):max_size(size){}
	virtual~SafeQueue() { terminate(); }

	void push(T new_data)
	{
		std::unique_lock<std::mutex> lk(mut);
		while (max_size == data_queue.size() && !is_terminate)
		{
			cond_put.wait(lk);
		}
		if (is_terminate)
		{
			return;
		}
		data_queue.push(std::move(new_data));           
		cond_get.notify_one();
	}

	void wait_and_pop(T& val)
	{
		std::unique_lock<std::mutex> ulk(mut);                   
		while (data_queue.empty() && !is_terminate)
		{
			cond_get.wait(ulk);
		}
		if (is_terminate)
		{
			return;
		}
		val = std::move(data_queue.front());
		data_queue.pop();
		cond_put.notify_one();
	}

	bool try_pop(T& val)
	{
		std::lock_guard<std::mutex> lk(mut);
		if (data_queue.empty())
			return false;
		val = std::move(data_queue.front());
		data_queue.pop();
		cond_put.notify_one();
		return true;
	}

	bool empty()
	{
		std::lock_guard<std::mutex> lk(mut);
		return data_queue.empty();
	}

	void terminate()
	{
		is_terminate = true;
		cond_get.notify_all();
		cond_put.notify_all();
	}

private:
	std::queue<T> data_queue;
	std::mutex mut;
	std::condition_variable cond_put;
	std::condition_variable cond_get;
	std::atomic<bool> is_terminate{false};
	int max_size;
};
































#endif // safeQueue_h__
