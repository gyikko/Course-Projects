### Feedback for Lab 10

Run on March 01, 20:44:01 PM.


### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+ Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		7439842e5c9b7f02def38076e280fe525aef2ae3	refs/heads/devel

		0b2522cc56a5b26f04bf4725240a54891ae70a58	refs/heads/fix/01-compilation-errors

		31f65a28935eabf331a4994f5f1f089d3290c0b1	refs/heads/fix/02-google-style

		75bf8b3cda4a8d1ef1933a965f0e1049566099ff	refs/heads/master



+ Pass: Checking for the correct number of branches

Sufficient branches found (found=2, required=2):

fix/01-compilation-errors

fix/02-google-style


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[jinxx679] 2020-03-01 (HEAD -> devel, origin/devel) trigger Feedback 

		[jinxx679] 2020-03-01 Merge branch 'fix/01-compilation-errors' into devel 

		[jinxx679] 2020-03-01 cpplint update 

		[jinxx679] 2020-03-01 fix(files): fix #1 <fix compilation problem> - Multiple lines of description
- Lists all the important elements that have been changed
- etc.


		[jinxx679] 2020-03-01 Replace src directory with Lab10 src 

		[jinxx679] 2020-03-01 Update project after deleting 



		[Jingyi Jin] 2020-02-29 Add lab09 

		[Jingyi Jin] 2020-02-29 Merge branch 'support-code' 

		[Jingyi Jin] 2020-02-29 Merge branch 'support-code' of github.umn.edu:umn-csci-3083-s20/csci3081-shared-upstream into support-code 














		[jinxx679] 2020-02-24 Lab 08 update 


		[jinxx679] 2020-02-24 Merge branch 'master' of github.umn.edu:umn-csci-3081-s20/repo-jinxx679 

		[jinxx679] 2020-02-24 Add Lab 08 



		[jinxx679] 2020-02-24 Add lab08 









		[jinxx679] 2020-02-21 Merge branch 'support-code' 

		[jinxx679] 2020-02-21 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream into support-code 





+ Pass: Check git commit history
Sufficient commits (found=18,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 2)

[OPEN issue #2] :  cpplint Errors [enhancement] 1

[OPEN issue #1] :  Prevent Compilation [bug] 1





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 0)

+ Pass: Run ghi for total number of issues in Github repo (Found: 2, Expected: 2) 

 [OPEN issue #2] :  cpplint Errors [enhancement] 1

[OPEN issue #1] :  Prevent Compilation [bug] 1

[CLOSED issue #] : 

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+ Pass: Check that directory "project/src" exists.

+ Pass: Change into directory "project/src".

+ Pass: Check that file "makefile" exists.

+ Pass: Check that make compiles.



