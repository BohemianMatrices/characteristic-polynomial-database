#!/bin/bash

# Prevent command from running when no files exist
shopt -s nullglob

# Characteristic polynomial files
for f in CharPolys_[0-9]*x[0-9]*.csv
do
	zip "$(basename "$f" .csv).zip" $f
	tar -czf "$(basename "$f" .csv).tar.gz" $f
done

# All characteristic polynomial files
zip CharPolys.zip CharPolys_[0-9]*x[0-9]*.csv
tar -czf CharPolys.tar.gz CharPolys_[0-9]*x[0-9]*.csv

# Minimal polynomial files
for f in MinPolys_[0-9]*x[0-9]*.csv
do
	zip "$(basename "$f" .csv).zip" $f
	tar -czf "$(basename "$f" .csv).tar.gz" $f
done

# All minimal polynomial files
zip MinPolys.zip MinPolys_[0-9]*x[0-9]*.csv
tar -czf MinPolys.tar.gz MinPolys_[0-9]*x[0-9]*.csv
