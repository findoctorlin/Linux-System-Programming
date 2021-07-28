src = $(wildcard *.c)
obj = $(patsubst %.c, %.o, $(src))

ALL:a.out

a.out:$(obj) header.h
	gcc $^ -o $@

$(obj):%.o:%.c
	gcc -c $< -o $@

clean:
	-rm -rf $(obj) a.out

.PHONY:clean ALL	#生成伪目标：防止同名文件阻碍clean和ALL的执行