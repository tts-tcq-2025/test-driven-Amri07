| Test ID | Test Name                        | Input                  | Expected Output / Behavior                 | Description                                 |
|---------|----------------------------------|------------------------|--------------------------------------------|---------------------------------------------|
| TC-01   | ReturnZeroForEmptyString         | `""`                   | `0`                                        | Empty string returns 0                      |
| TC-02   | ReturnSingleNumber               | `"1"`                  | `1`                                        | Single number                               |
| TC-03   | SumTwoCommaSeparatedNumbers      | `"1,2"`                | `3`                                        | Two numbers, comma separated                |
| TC-04   | SumUnknownAmountOfNumbers        | `"1,2,3,4,5"`          | `15`                                       | Any amount of comma separated numbers       |
| TC-05   | HandleNewLineAsDelimiter         | `"1\n2,3"`             | `6`                                        | Newline and comma as delimiters             |
| TC-06   | CustomSingleCharDelimiter        | `"//;\n1;2"`           | `3`                                        | Custom delimiter (single char)              |
| TC-07   | CustomMultiCharDelimiter         | `"//[***]\n1***2***3"` | `6`                                        | Custom delimiter (multi-char)               |
| TC-08   | IgnoreNumbersGreaterThan1000     | `"2,1001"`             | `2`                                        | Numbers > 1000 are ignored                  |
| TC-09   | NegativeNumberThrowsException    | `"1,-2"`               | Exception: `negatives not allowed: -2`     | Negative number throws exception            |
| TC-10   | MultipleNegativesInException     | `"1,-2,-3"`            | Exception: `negatives not allowed: -2,-3`  | All negatives listed in exception           |
