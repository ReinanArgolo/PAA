#!/bin/bash
echo "Compilando..."
g++ presentes.cpp -o presentes -O2

if [ $? -ne 0 ]; then
    echo "Erro de compilação!"
    exit 1
fi

cat << 'IN' > input.txt
2
3 2
1 1 2 3
2 2 1 1
3 2 2 1
2 1
32 4 5 1
25 10 1 2
IN

cat << 'OUT' > expected.txt
1 3
25
OUT

echo "Executando testes..."
./presentes < input.txt > output.txt

if cmp -s output.txt expected.txt; then
    echo "✅ Test Passed!"
else
    echo "❌ Test Failed!"
    echo "--------------------------"
    echo "Expected:"
    cat expected.txt
    echo "--------------------------"
    echo "Got:"
    cat output.txt
    echo "--------------------------"
fi
