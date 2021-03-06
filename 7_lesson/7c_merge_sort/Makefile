MAINNAME= merge_sort

##########################################################
# sources files
##########################################################
# There is no SRCTESTMAIN as we are linking with gtest_main that has main
SRCSTESTNOMAIN= $(MAINNAME).cpp
##########################################################


#########################################################
# compiler stuff 
#########################################################
CXX= g++
CXXFLAGS= -Wall -Wvla -Werror -g -std=c++11

CXXTESTLINKFLAGS= -lgtest -lgtest_main -pthread
##########################################################


#######################
# executables name
#######################
TEST= test_$(MAINNAME)
#######################


#########################################################
# actions
#########################################################
all: $(TEST)

$(TEST): $(subst .cpp,.o,$(SRCSTESTNOMAIN))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(CXXLINKFLAGS) $(CXXTESTLINKFLAGS)
	./$@

clean:
	rm *.o $(TEST) -f

depend: $(SRCSTESTNOMAIN)
	makedepend -Y -- $(CXXFLAGS) -- $^

##############################################
# installs that should be done once
##############################################
installonce: gtestinstall makedependinstall valgrindinstall

gtestinstall: 
	sudo apt-get install libgtest-dev
	sudo apt-get install cmake
	cd /usr/src/gtest; \
	sudo cmake CMakeLists.txt; \
	sudo make; \
	sudo cp *.a /usr/lib
	sudo chmod u+r /usr/lib/libgtest.a
	sudo chmod u+r /usr/lib/libgtest_main.a

makedependinstall:
	sudo apt-get install xutils-dev

valgrindinstall:
	sudo apt-get install valgrind
##############################################

.PHONY: all clean depend installonce gtestinstall makedependinstall valgrindinstall


# DO NOT DELETE THIS LINE -- make depend depends on it.
