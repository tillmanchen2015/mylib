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
	SafeQueue() {}
	virtual~SafeQueue() { terminate(); }

	void push(T new_data)
	{
		std::lock_guard<std::mutex> lk(mut);            
		data_queue.push(std::move(new_data));           
		cond.notify_one();
	}

	void wait_and_pop(T& val)
	{
		std::unique_lock<std::mutex> ulk(mut);                   
		cond.wait(ulk, [this]() { return !data_queue.empty() || is_terminate; }); 
		if (is_terminate)
		{
			return;
		}
		val = std::move(data_queue.front());
		data_queue.pop();
	}

	bool try_pop(T& val)
	{
		std::lock_guard<std::mutex> lk(mut);
		if (data_queue.empty())
			return false;
		val = std::move(data_queue.front());
		data_queue.pop();
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
	}

private:
	std::queue<T> data_queue;
	std::mutex mut;
	std::condition_variable cond;
	std::atomic<bool> is_terminate{false};
};
































#endif // safeQueue_h__
