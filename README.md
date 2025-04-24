# ライフゲーム（LIFE GAME）

## 概要
このプログラムは「ライフゲーム」と呼ばれるセルオートマトンをシミュレーションします。ジョン・コンウェイによって考案されたこの「ゲーム」では、特定のルールに従って格子上のセルが生きたり死んだりします。

## パラメータ設定
- **初期状態の生物数**: 8生物
  - 0世代: 初期の生物配置
  - 2世代: 2世代目の生物配置
  - 4世代: 4世代目の生物配置

- **ルール**: B3/S23
  - B3: 死んでいるセルの周囲に生きたセルが3つあると誕生
  - S23: 生きているセルの周囲に生きたセルが2つか3つあると生存継続

- **フィールドSIZE**: 20 x 20
  - 20x20のグリッドでシミュレーションを実行

## 使用方法
初期化パラメータ（INIT, SIZE）を設定し、シミュレーションを開始します。世代ごとの生物の進化を観察できます。

## 注意事項
このプログラムを実行するには、指定された初期パラメータを正確に設定してください。

---

# LIFE GAME

## Overview
This program simulates a cellular automaton called "Life Game" (Conway's Game of Life). Devised by John Conway, this "game" consists of cells on a grid that live or die according to specific rules.

## Parameter Settings
- **Initial Number of Organisms**: 8 organisms
  - Generation 0: Initial organism placement
  - Generation 2: Organism placement in generation 2
  - Generation 4: Organism placement in generation 4

- **Rules**: B3/S23
  - B3: A dead cell with exactly 3 live neighbors will be born
  - S23: A live cell with 2 or 3 live neighbors survives

- **Field SIZE**: 20 x 20
  - Simulation runs on a 20x20 grid

## How to Use
Set the initialization parameters (INIT, SIZE) and start the simulation. You can observe the evolution of organisms across generations.

## Note
To run this program, please set the specified initial parameters correctly.