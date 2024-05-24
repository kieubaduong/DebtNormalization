# DebtNormalization

## Description

This project contains an implementation of a debt normalization algorithm. The algorithm takes a 2D matrix representing debts between entities and normalizes it, such that if entity A owes entity B a certain amount, and entity B owes entity A a different amount, the debts are offset against each other.

## How to Use

Just simply replace value in the matrix with the amount of debt between two entities. The algorithm will normalize the debt and print out the result.

## Example data

|            | Hoa | Duong | Khanh | Hung | Vu  |
| ---------- | --- | ----- | ----- | ---- | --- |
| Hoa debt   |     |       |       |      |     |
| Duong debt |     |       |       |      |     |
| Khanh debt |     |       |       |      |     |
| Hung debt  |     |       |       |      |     |
| Vu debt    |     |       |       |      |     |
