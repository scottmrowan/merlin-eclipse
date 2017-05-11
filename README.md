# MERLIN install guide

# Make sure ~/git/merlin-eclipse not not currenly in use

- download eclipse cdt for c/c++
- install egit plugin

- open eclipse
- file > import
- under Git, select "Projects from Git" > next
- select Clone from URI > next
- copy "https://github.com/scottmrowan/merlin-eclipse" into URI (the rest should autocomplete) > next
- make sure only master branch is selected > next
- make sure Import existing Eclipse projects is selected > next
- make sure both MerlinLibrary and UserProject are selected > finish

# wait for download (should be % indexer bottom right of workspace window)

- select MerlinLibrary > build Release (click the submenu arrow next to the hammer)
 
 # wait for build (2-5 mins on most modern systems)
 
 - select UserProject > build Release
 - select Run as... Local C/C++ Application
 
 you should receive a Success!! output if all went well
 
# import example projects from "https://github.com/scottmrowan/merlin-examples" in the same manner
# no need to re-import the library


