CC = gcc

target_name=branch_predict_test
target_suffix=
suffix_name=_sort

ifeq ($(SORT), y)
	target_suffix=suffix_name
endif

target=$(target_name)$(target_suffix)

all: $(target)

$(target): branch_predict_test.c
	$(CC) -Wall -Wextra -o $@ branch_predict_test.c

clean:
	rm -f $(target_name)$(suffix_name) $(target_name)
