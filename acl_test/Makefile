

BASE_PATH= /home/zt/git_src/acl

CFLAGS = -c -g -W -O3 -Wall -Werror -Wshadow \
				 -Wno-long-long -Wpointer-arith -D_REENTRANT \
				 -D_POSIX_PTHREAD_SEMANTICS -DLINUX2 \
				 -I $(BASE_PATH)/lib_acl_cpp/include

LDFLAGS = -L$(BASE_PATH)/lib_acl_cpp/lib -l_acl_cpp \
					-L$(BASE_PATH)/lib_protocol/lib -l_protocol \
					-L$(BASE_PATH)/lib_acl/lib -l_acl \
					-lpthread

all:
	g++ acl.cpp -o acl.o $(CFLAGS)
	g++ acl.o -o a $(LDFLAGS) 

clean:
	rm -f a *.o

