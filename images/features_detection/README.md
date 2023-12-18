<!--
 FileName:      README
 Author:        8ucchiman
 CreatedDate:   2023-04-25 12:38:03
 LastModified:  2023-01-25 10:56:12 +0900
 Reference:     
 Description:   ---
-->


# harris corner detector
`コーナー検出` `テイラー展開`



# [FAST](http://labs.eecs.tottori-u.ac.jp/sd/Member/oyamada/OpenCV/html/py_tutorials/py_feature2d/py_fast/py_fast.html)
`注目画素に対して周囲画素を定義し、それらの輝度の比較によって特徴点検出` `決定木`
Features from Accelerated Segment Test

## algorithm

1. 画像中から画素pを選択し、その画素値を$I_p$とする。
2. 適切な閾値tを選択
3. 注目画素を中心とし円周が16画素となる円を考える
4. 円上の連続するn画素の画素値が$I_p+t$より高い、もしくは$I_p-t$より低いとき、その画素pをコーナーとして検出
5. 高速テストは大量の非コーナーを排除するために行う。はじめに円周上の4画素のみでテストし、ふるいに立てる。

## 問題点
1. $n(16画素のうちのn画素)<12$と設定すると、多くの候補を除外しなくなる。
2. 計算効率がテストの順番とコーナーの分布に依存するため、画素の選択方法が最適ではない。
3. 高速テストの結果は棄却される。
4. 隣接する画素が両方ともコーナーとして検出

## 機械学習の導入(問題点1,2,3への対応)
1. 学習用の画像セット選択
2. 全ての画像に対してFASTによる特徴点の検出を行う。
3. 検出した全ての特徴点に対して、各特徴点の周囲の16画素の画素値を特徴ベクトル$p$として保持
4. 16画素中の各画素xは以下のいずれかの状態になる。

$ S_{p\rightarrow x} = d     I_{p\rightarrow x}<I_p-t$
$ S_{p\rightarrow x} = s     I_p-t < I_{p\rightarrow x} < I_p+t$
$ S_{p\rightarrow x} = b     I_p+t < I_{p\rightarrow x}$

5. 画素の状態に応じて特徴ベクトルpが3つのに分割される。
6. 画像pにはコーナーかコーナー出ないかという2つのラベルが存在する。
7. ID3を使って各


5. 画素の状態に応じて特徴ベクトルpを3つの部分集合


# BLOB
# SURF
# SIFT
# ORB
# BRISK
# KAZE
# AKAZE
# FREAK
# DAISY
# BRIEF

# DoG画像
`特徴点とその領域の大きさを表すスケールを検出`



# SIFT
`特徴点のスケールに合わせた領域に対して、回転に不変な特徴量を記述するためにオリエンテーションを算出`
