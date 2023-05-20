<!--
 FileName:      readme
 Author:        8ucchiman
 CreatedDate:   2023-04-26 13:58:51
 LastModified:  2023-01-25 10:56:12 +0900
 Reference:     https://cvml-expertguide.net/terms/cv/image-feature-detection/harris-corner-detector/
 Description:   ---
-->


# harris corner detector

## 理論
全方向に対して画素位置(u, v)の移動量に対する画素値の違いを検出


$E(u, v) = \sum_{(x, y)\in W}w(x, y)[I(x+u, y+v)-I(x, y)]^2 $
平行移動量(u, v)が非常に小さいと仮定, (u, v)に対して拘束条件$u^2+v^2=1$が加わる。
仮定から、テイラー展開をする。
$E(u, v) = \sum_{(x, y)\in W}w(x, y)[I(x, y)+I_{x}(x)\times u + I_{y}(y)\times v - I(x, y)]^2$
$E(u, v) = \sum_{(x, y)\in W}w(x, y)[I_{x}(x)\times u + I_{y}(y)\times v]^2$

これを行列Mを用いて以下のように書き直すことができる。


$E(x, y) = \begin{pmatrix} u & v \end{pmatrix} M \begin{pmatrix} u \\ v \end{pmatrix}$
ただし、Mは次のような成分からなる行列である。
$M = \sum_{(x, y)\in W} \begin{pmatrix} I^{2}_{x}(x, y) & I_{x}(x, y)I_{y}(x, y) \\ I_{x}(x, y)I_{y}(x, y) & I^{2}_{y}(x, y) \end{pmatrix}$

$\begin{pmatrix} u & v \end{pmatrix} M \begin{pmatrix} u \\ v \end{pmatrix} = \sum_{(x, y)\in W}w(x, y)[I_{x}(x)\times u + I_{y}(y)\times v]^2$

ここからMの固有値を計算する。

## コーナーネス計算
計算コストを考え、コーナーネス関数Rを定義する。
このRをコーナー検出のスコアとする。
$R = det(M) - k (tr(M))^2 (k: 0.04~0.06 empilically)$
$det(M) = \lambda_{1}\lambda_{2}$
$tr(M) = \lambda_{1}+\lambda_{2}$
