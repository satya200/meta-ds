STEPS TO COMMIT CHANGES:
---------------------------

1> 1st update your branch from develop

2> Do the changes

3> After verify your changes by using below command
	git diff

4> If it is ok check status by "git status" command

5> If you want to add all your changes use
	git add .

6> Use "git commit -s -v" to commit your changes

7> USE BELOW COMMAND TO PUSH YOUR CHANGES TO YOUR OWN BRANCH
   NOTE:- DON'T PUSH TO DEVELOP OR MASTER BRANCH
	git push -u orgin <ur branch>
   Example:-
	git push -u orgin sumit-dev

# meta-ds
-----------
This repo contains all data structures program.

1. Folder single_linklist
	It contails all kind of Single linked list function.

2. Folder double_linklist
	It Contains all kind of Double linked list Function

3. Folder double_linklist_opt
	This Folder contains optimize double linked list
	This is implemented using single self referncial
	pointer using exor to find out next node.

4. Folder stack
	This Folder Contains Stack implementation

5. Folder bst_tree
	This Folder contains binary search tree.

6. Folder queue
	This Folder contains Queue Implementation.


Steps To Build:
----------------
	Just Give make inside mest-ds Directory. All binarys are
	created inside meta-ds/<respective> Folder
	To Build lib:
	---------------
		1> make -> inside meta-ds folder
		2> make lib -> Create shared lib in current folder
		3> Put this Lib inside /usr/lib
		4> Compile your App with "-lDataStructure"
			Please refer application present inside respective module folder name app.c or main.c
