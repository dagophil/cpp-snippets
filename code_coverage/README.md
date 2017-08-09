## How to get code coverage information:

1. Compile. Compilation flags such as `-O3` are possible, but the results are imprecise. For example, the compiler does not create code for unused inline functions such as `Foo::bar1()`. Since the function does not produce compiled code, they are not counted by the code coverage.

	```
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 -o main main.cpp foo.cpp
	```

2. Execute at least once. Line counts of consecutive executions add up!

	```
	main.exe
	```

3. Generate code coverage file. This outputs useful information such as `Lines executed:71.43% of 7`.

	```
	gcov main.cpp foo.cpp
	```

4. Open `main.cpp.gcov`, `foo.cpp.gcov`, or `foo.h.gcov` to see how often each line was executed.

5. Pretty print the results using `gcovr` (install with `pip install gcovr`). This automatically invokes `gcov`, so step 3 is not necessary.

	Command | Result
	--------|-------
	`gcovr` | Tabular output in console
	`gcovr --html -o coverage.html` | HTML output
	`gcovr --html --html-details -o coverage.html` | HTML output with line counts
