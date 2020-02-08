### Feedback for Lab 03

Run on February 08, 14:03:03 PM.


#### Necessary Files and Structure

+ Pass: Check that directory "googletest" exists.

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab03_class_basics" exists.

+ Pass: Change into directory "labs/lab03_class_basics".


#### Essential Files Exist

+ Pass: Check that file "Makefile" exists.

+ Pass: Check that file "Makefile.test" exists.

+ Pass: Check that file ".gitignore" exists.

+ Pass: Check that file "point2.cc" exists.

+ Pass: Check that file "point2.h" exists.

+ Pass: Check that file "point2_unittest.cc" exists.


#### .gitignore set up properly

+ Pass: Check that file/directory "cluster" does not exist.

+ Pass: Check that file/directory "point2_unittest" does not exist.

+ Pass: Check that no files with extension ".o" exist in directory "."

+ Pass: Check that no files with extension ".out" exist in directory "."


#### Test that code compiles and creates the exectuable

+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>g++ -c -Wall main.cc -o main.o
In file included from main.cc:13:0:
point2.h:8:34: error: o was not declared in this scope
     Point2 (float xx=0, float yy=o) {xx=x; yy=y; };
                                  ^
main.cc: In function int main():
main.cc:26:10: error: call to Point2::Point2(float, float) uses the default argument for parameter 2, which is not yet defined
   Point2 origin;
          ^~~~~~
main.cc:27:36: error: call to Point2::Point2(float, float) uses the default argument for parameter 2, which is not yet defined
   Point2 random_cluster[point_count];
                                    ^
main.cc: In function void DisplayTwoClosest(Point2*):
main.cc:64:55: error: no matching function for call to Point2::DistanceBetween(Point2&)
       distance = cluster[i].DistanceBetween(cluster[j]);
                                                       ^
In file included from main.cc:13:0:
point2.h:9:11: note: candidate: float Point2::DistanceBetween()
     float DistanceBetween();
           ^~~~~~~~~~~~~~~
point2.h:9:11: note:   candidate expects 0 arguments, 1 provided
main.cc: In function void DisplayFarthestFrom(Point2, Point2*):
main.cc:82:58: error: no matching function for call to Point2::DistanceBetween(Point2&)
   float max_from_point = point.DistanceBetween(cluster[0]);
                                                          ^
In file included from main.cc:13:0:
point2.h:9:11: note: candidate: float Point2::DistanceBetween()
     float DistanceBetween();
           ^~~~~~~~~~~~~~~
point2.h:9:11: note:   candidate expects 0 arguments, 1 provided
main.cc:86:48: error: no matching function for call to Point2::DistanceBetween(Point2&)
     distance = point.DistanceBetween(cluster[i]);
                                                ^
In file included from main.cc:13:0:
point2.h:9:11: note: candidate: float Point2::DistanceBetween()
     float DistanceBetween();
           ^~~~~~~~~~~~~~~
point2.h:9:11: note:   candidate expects 0 arguments, 1 provided
main.cc: In function void DisplayQuadrantCount(Point2*):
main.cc:104:29: error: no matching function for call to Point2::Quadrant()
     if (cluster[i].Quadrant() == 0)
                             ^
In file included from main.cc:13:0:
point2.h:10:10: note: candidate: void Point2::Quadrant(int, int)
     void Quadrant(int x, int y);
          ^~~~~~~~
point2.h:10:10: note:   candidate expects 2 arguments, 0 provided
main.cc:107:36: error: no matching function for call to Point2::Quadrant()
     quad_count[cluster[i].Quadrant()-1]++;
                                    ^
In file included from main.cc:13:0:
point2.h:10:10: note: candidate: void Point2::Quadrant(int, int)
     void Quadrant(int x, int y);
          ^~~~~~~~
point2.h:10:10: note:   candidate expects 2 arguments, 0 provided
Makefile:10: recipe for target 'main.o' failed
make: *** [main.o] Error 1
</pre>



+ Skip: Check that file "cluster" exists.

  This test was not run because of an earlier failing test.

+ Skip: Check that make compiles for Makefile:Makefile.test.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

