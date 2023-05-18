.PHONY = build:

build:
	g++ -pthread 000\ basic\ multithreading.cpp -o basic_multithreading &
	g++ -pthread 001\ shared\ data.cpp -o shared_data &
	g++ -pthread 002\ mutexes.cpp -o mutexes &
	g++ -pthread 003\ passing\ arguments.cpp -o passing_arguments &
	g++ -pthread 004\ lock_guard.cpp -o lock_guard &
	g++ -pthread 005\ threads\ with\ callable\ objects.cpp -o threads_with_callable_objects &
	g++ -pthread 006\ calculating\ PI\ exercise.cpp -o calculating_pi &
	g++ -pthread 007\ promises\ and\ futures\ function\ args.cpp -o promises_and_future &
	g++ -pthread 008\ promises\ and\ futures\ lambda\ expr\ for\ promise.cpp -o mutexes &
	g++ -pthread 009\ promises\ and\ futures\ with\ exception.cpp -o promises_and_futures_with_exception 
