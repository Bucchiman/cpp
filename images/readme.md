<!-- FileName: readme
 Author: 8ucchiman
 CreatedDate: 2023-03-08 00:10:04 +0900
 LastModified: 2023-03-08 00:21:46 +0900
 Reference: 8ucchiman.jp
-->


# γ補正


カメラなどのデバイスによって画素値が非線形的に変換された場合の補正である。
ディスプレイなどで画像をそのまま表示すると画面が暗くなってしまうので、RGBの値をあらかじめ大きくすることで
ディスプレイの特性を排除した画像表示を行うことがγ補正の目的である。

非線形変換は次式で起こるとされる。
x=[0, 1], c...定数, g...γ特性

```
    x' = cIin^g
```

γ補正は次式で行われる。
```
    Iout = (1/cIin)^(1/g)
```


# 最近傍補間

画像の拡大時に最近傍にある画素をそのまま使う方法。


# harris corner detector
# lukas kanade
# sift
# mean shift
# surf
# fast
# orb


# 判別分析法
`白黒画像の最適な閾値を決める手法` `クラス間の分散を最大にする`
