# 概要
struct complexは複素数を表す構造体です。
# 依存
このリポジトリは[fraction](https://github.com/takechan-NITNC/fraction)に依存しています。
# 仕様
## メンバ
### struct fraction re
実部を表します。
### struct fraction im
虚部を表します。
## 関数
### struct complex fraction_to_complex(struct fraction)
指定した分数を実部に持ち虚部が０の複素数を返します。分母が０である分数を実部か虚部に含む複素数を与えるとエラーメッセージを表示してプログラムを強制終了します。
### struct complex int_to_complex(int)
指定した整数を実部に持ち虚部が０の複素数を返します。
### struct complex complex_sum(struct complex, struct complex)
指定した２つの複素数の和を返します。

分母が０である分数を実部か虚部に含む複素数を与えるとエラーメッセージを表示してプログラムを強制終了します。オーバーフローは考慮されません。
### struct complex complex_substract(struct complex, struct complex)
１つ目に指定した複素数から２つ目に指定した複素数を引いた差を返します。

分母が０である分数を実部か虚部に含む複素数を与えるとエラーメッセージを表示してプログラムを強制終了します。オーバーフローは考慮されません。
### struct complex complex_product(struct complex, struct complex)
指定した２つの複素数の積を返します。オーバーフローは考慮されません。
### struct complex complex_divide(struct complex, struct complex)
１つ目に指定した複素数を２つ目に指定した複素数で割った商を返します。

分母が０である分数を実部か虚部に含む複素数を与えるとエラーメッセージを表示してプログラムを強制終了します。除数が０の場合もエラーメッセージを表示してプログラムを強制終了します。オーバーフローは考慮されません。