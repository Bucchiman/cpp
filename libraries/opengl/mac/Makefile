#
# FileName:     Makefile
# Author: 		8ucchiman
# CreatedDate:  2023-08-20 16:51:47
# LastModified: 2023-02-03 21:27:40 +0900
# Reference: 	https://qiita.com/chibi929/items/b8c5f36434d5d3fbfa4a
# Description:	---
#





.PHONY: sample_filter \
	    sample_filter_out \
		sample_firstword \
		sample_lastword \
		sample_patsubst \
		sample_sort \
		sample_strip \
		sample_subst \
		sample_word \
		sample_wordlist \
		sample_words \
		sample_subst \
		sample_abspath


# 静的ライブラリ作成
static: *.o
	ar rvs libhoge.a geho.o

# 共有ライブラリ作成
dynamic: *.o
	g++ -shared hoge.o -o libhoge.so


.PHONY: clean
clean:
	rm *.png *.pdf *.jpg *.aux *.dvi *.log

# - $(filter PATTERN..., TEXT)  PATTERNの文字列に一致する要素を取得
VAR := hoge.h hoge.cpp geho.h geho.cpp
sample_filter:
	@echo "$(filter %.cpp, $(VAR))" # -> hoge.cpp, geho.cpp

# - $(filter-out PATTERN..., TEXT) PATTERNの文字列に一致しない要素
VAR := hoge.h hoge.cpp geho.h geho.cpp
sample_filter_out:
	@echo "$(filter-out %.cpp, $(VAR))" # -> hoge.h geho.h

# - $(findstring FIND, IN) IN内にFINDの文字列があれば、その文字列を抽出
VAR := abc def ghi
sample_findstring:
	@echo "$(findstring bc, $(VAR))" # -> bc

# - $(firstword NAMES...) NAMES内の最初の要素を取得
VAR := abc def ghi
sample_firstword:
	@echo "$(firstword $(VAR))" # -> abc

# - $(lastword NAMES...) NAMES内の最後の要素を取得
VAR := abc def ghi
sample_lastword:
	@echo "$(lastword $(VAR))" # -> ghi

# - $(patsubst PATTERN,REPLACEMENT,TEXT) TEXT内からPATTERNにマッチしたものをREPLACEMENTに置き換える。
VAR := hoge.cpp geho.cpp
sample_patsubst:
	@echo "$(patsubst %.cpp, %.o, $(VAR))" # -> hoge.o geho.o

# - $(sort LIST)
VAR := hoge foo geho fuga
sample_sort:
	@echo "$(sort $(VAR))" # -> foo fuga geho hoge

# - $(strip STRING) STRINGの無駄な空白を取り除く
VAR := a b  c     d
sample_strip:
	@echo "$(strip $(VAR))" # -> a b c d

# - $(subst FROM, TO, TEXT) TEXT内のFROMをTOに置き換える
VAR := hoge.cpp geho.cpp
sample_subst:
	@echo "$(subst .cpp, .o, $(VAR))"

# - $(word N,TEXT) TEXT内のN番目の要素を取得
VAR := abc def ghi
sample_word:
	@echo "$(word 1, $(VAR))"

# - $(wordlist S, E, TEXT) TEXTのSからEまでの要素を取得
VAR := abc def ghi
sample_wordlist:
	@echo "$(wordlist 1, 2, $(VAR))" # -> abc def

# - $(words TEXT) TEXTの要素数を取得
VAR := abc def ghi
sample_words:
	@echo "$(words $(VAR))" # -> 3

# - $(abspath NAMES...) NAMESの各要素の絶対パスを取得
VAR := ../ ./ Makefile
sample_abspath:
	@echo "$(abspath $(VAR))"

