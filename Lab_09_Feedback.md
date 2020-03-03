### Feedback for Lab 09

Run on March 02, 19:22:21 PM.


#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Change into directory "project".

+ Pass: Check that directory "config" exists.

+ Pass: Check that directory "docs" exists.

+ Pass: Check that directory "drivers" exists.

+ Pass: Check that directory "src" exists.

+ Pass: Check that directory "tests" exists.

+ Pass: Check that directory "web_code/web" exists.

+ Pass: Check that directory "web_graphics" exists.


#### .gitignore configured properly

+ Pass: Check that file/directory "build" does not exist.

+ Pass: Check that file/directory "build/bin/vis_sim" does not exist.


#### Compile Tests

+ Pass: Change into directory "src".

+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>==== Auto-Generating Dependencies for passenger_factory.cc. ====
==== Compiling passenger_factory.cc into /project/grades/Spring-2020/csci3081/student-repos/Lab_09_Feedback/repo-jinxx679/project/build/obj/transit_sim/passenger_factory.o. ====
==== Auto-Generating Dependencies for bus.cc. ====
==== Compiling bus.cc into /project/grades/Spring-2020/csci3081/student-repos/Lab_09_Feedback/repo-jinxx679/project/build/obj/transit_sim/bus.o. ====
==== Auto-Generating Dependencies for random_passenger_generator.cc. ====
==== Compiling random_passenger_generator.cc into /project/grades/Spring-2020/csci3081/student-repos/Lab_09_Feedback/repo-jinxx679/project/build/obj/transit_sim/random_passenger_generator.o. ====
random_passenger_generator.cc:24:1: error: version control conflict marker in file
 <<<<<<< HEAD
 ^~~~~~~
random_passenger_generator.cc:74:1: error: version control conflict marker in file
 <<<<<<< HEAD
 ^~~~~~~
makefile:102: recipe for target '/project/grades/Spring-2020/csci3081/student-repos/Lab_09_Feedback/repo-jinxx679/project/build/obj/transit_sim/random_passenger_generator.o' failed
make: *** [/project/grades/Spring-2020/csci3081/student-repos/Lab_09_Feedback/repo-jinxx679/project/build/obj/transit_sim/random_passenger_generator.o] Error 1
</pre>



+ Skip: Change into directory "..".

  This test was not run because of an earlier failing test.

+ Skip: Check that file "build/bin/vis_sim" exists.

  This test was not run because of an earlier failing test.

