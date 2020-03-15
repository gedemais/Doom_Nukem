#!/bin/bash

echo "Dependencies check..."

if brew ls --versions libsndfile > /dev/null; then
	echo "libsndfile found"
else
	echo "libsndfile missing, installing it with brew..."
	brew install libsndfile && brew link libsndfile
fi

if brew ls --versions openal-soft > /dev/null; then
	echo "openal-soft found"
else
	echo "openal-soft missing, installing it with brew..."
	brew install openal-soft && brew link openal-soft
fi
