# FMP3+TECS
このFMP3+TECSは[TOPPERS/FMP3](https://www.toppers.jp/fmp3-kernel.html)をにTECSを適用し、コンポーネント化したものです。
<br>
各コンポーネントのファイルについては[fmp3+tecsのtrac](https://dev.toppers.jp/trac/tecs/browser/toppers/fmp3%2Btecs)から拝借しています。

#### サンプルプログラム
複数あるが、いずれもカーネルの各機能をチェックするためのもの。tから始まるものがTECS対応版。
<br>
タスクが周期的に呼び出され、ターミナルに文字列を出力する。
<br>
また、入力した文字に応じてタスクの挙動や優先度などを変更することができる。

#### 開発環境
1. XSDKインストール

   -[XilinxのHP](https://japan.xilinx.com/support/download/index.html/content/xilinx/ja/downloadNav/embedded-design-tools.html)からSDKをインストール。

   -SDK 2019.1での動作は確認済み。

   -インストールする際にサインインを求められます。無料で登録できるのでアカウント作成してください。

   -必要に応じて環境変数を設定してください。

3. 対象ボード

   -Zybo Z7_10 Zynq-7010 ARM開発ボード
   
   -ARM Cortex-A9を搭載したデュアルコアの開発ボードです。

   -USB接続をして、スイッチをONにすると使えます。

#### ビルド・実行手順
以下はいずれもXSDK上での操作になります。
1. ワークスペースの選択

   -XSDK起動時に問われるので、このフォルダを選択してOKを押す。
   
2. ビルド

   -Project Explorerを開いた状態で、プロジェクト名（sample1など）を右クリック。

   -Build Projectを選択することでビルドができる。

   -完了すると、"プロジェクト名.elf"という実行ファイルが生成される。

3. デバッグ・実行

   -ボードをUSB接続して、画面下のターミナルにある”＋”のボタンをクリック。接続設定のウィンドウが出るので、portを選択する（そのほかは基本ノータッチでOK）。

   -ボードが接続できると、”Connected to (ポート番号) at (Baud Rate)”と表示される。

   -ボードが接続出来たら、"プロジェクト名.launch"を右クリック。

   -"Debug As -> プロジェクト名"と選択すると、デバッガが起動する（Project Explorerをデバッガは画面右上のマークをクリックして切り替え可能）。

   -途中でダイアログが出た場合はYesで進む。

   -画面上部の実行ボタンをクリックすることで実行可能。
