# libft tests

libft の各関数を、本家の libc 関数や期待値と比べて確認するテスト集です。
`tests/test_all.sh` を 1 回実行すると、次の順番でまとめて確認できます。

1. `norminette` (`*.c` と `*.h`)
2. `make fclean`
3. `make`
4. もう一度 `make` (再リンクしないことの確認)
5. 関数ごとのテスト (AddressSanitizer 付きでビルドして実行)

## 必要なもの

| ツール | 用途 |
| --- | --- |
| `cc` | テストのビルド |
| `make` | `libft.a` のビルド |
| `norminette` | Norm チェック |
| `libbsd` (`libbsd-dev`) | `strlcpy` / `strlcat` / `strnstr` の比較用 (`-lbsd`) |
| `valgrind` | 任意。`ccwtest -v` を使うときだけ必要 |

## ファイル構成

| ファイル | 内容 |
| --- | --- |
| `test_all.sh` | 全テストをまとめて実行するスクリプト |
| `test_ft_*.c` | 関数ごとのテスト (1 ファイルに 1 つの `main`) |
| `test_libft.h` | テスト共通のヘッダ。`../libft.h` を読み込む |
| `utils.c` | `result()` / `result_all()` / `check_output()` などの共通関数 |
| `test_template.c` | 新しいテストを書くときのひな形 |

## 設置方法

このテスト集は公開リポジトリ
[yusuke1225math2/libft-test-v19.3](https://github.com/yusuke1225math2/libft-test-v19.3)
で配布しています。自分の libft フォルダ (以下 `your_libft/`) の直下で、`tests` という名前を付けて
`git clone` します。

```bash
cd ~/your_libft
git clone https://github.com/yusuke1225math2/libft-test-v19.3.git tests
```

最後の `tests` は clone 先のフォルダ名です。省略すると
`libft-test-v19.3/` という名前になり、テストが動かないので必ず付けてください。

設置後は次のような構成になります。

```text
your_libft/
├── Makefile
├── libft.h
├── ft_*.c
└── tests/
    ├── README.md
    ├── test_all.sh
    ├── test_libft.h
    ├── utils.c
    ├── test_template.c
    └── test_ft_*.c
```

注意点:

- `your_libft/` が Git リポジトリの場合、`tests/` は別リポジトリなので
  提出物に含めないでください。`your_libft/.gitignore` に `tests/` を追加しておくと
  誤って `git add` するのを防げます。

- `test_libft.h` は `#include "../libft.h"` で自分のヘッダを読み込むため、
  必ず `your_libft/tests/` という位置に置いてください。
- `Makefile` が `libft.a` を作り、`fclean` ルールを持っている必要があります。
- テスト中のコマンドは `tests/utils.c` や `libft.a` を相対パスで参照するので、
  実行は必ず `your_libft/` 直下から行います。

## 実行方法

### 1. `your_libft/` 直下に移動する

```bash
cd ~/your_libft
```

### 2. 実行する

```bash
sh tests/test_all.sh
```

zsh を使っている場合は、次の形でも同じように動きます。

```bash
./tests/test_all.sh
```

bash から `./tests/test_all.sh` で実行するのは避けてください。
`test_all.sh` には shebang (`#!/bin/sh`) がないため、bash から実行すると
bash 自身がスクリプトを解釈します。非対話の bash ではエイリアス (`ccw`) が
展開されず、最後の `ft_lstmap` のテストが `ccw: command not found` になります。
また `echo "\n..."` の `\n` もそのまま表示されます。
`sh tests/test_all.sh` ならどのシェルからでも同じ結果になります。

出力をファイルに残したいときは、次のようにします。

```bash
sh tests/test_all.sh 2>&1 | tee test.log
```

## 結果の見方

各テストは、ケースごとに `OK` / `KO` を表示し、最後にまとめを出します。

```text
===== test_ft_strlen =====
OK: ""
OK: "12345"
OK: embedded NUL

all tests passed
```

- `KO: <ケース名>` が出たら、そのケースが失敗しています。
- 失敗があると最後に `N test(s) failed` と表示されます。
- AddressSanitizer がメモリエラーやリークを見つけると `ERROR: AddressSanitizer`
  や `ERROR: LeakSanitizer` のレポートが表示されます。

## 特定の関数だけテストする

`tests/test_all.sh` を開き、テストしたい関数の行以外を `#` でコメントアウトしてから、
いつもと同じように実行します。

```sh
# ccwtest ft_isalpha.c
# ccwtest ft_isdigit.c
ccwtest ft_strlen.c
# ccwtest ft_memset.c
```

```bash
sh tests/test_all.sh
```

norminette と make の行も、不要であれば同じようにコメントアウトできます。

最後の `ft_lstmap` のテストは 2 行に分かれているので、コメントアウトするときは
2 行とも `#` を付けてください。
