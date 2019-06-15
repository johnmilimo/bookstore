#!/bin/bash

gcc book_store_test.c book_store.c ./unity/unity.c -o book_store_test
./book_store_test