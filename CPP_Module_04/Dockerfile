# Use an official Ubuntu-based image as the base
FROM ubuntu:latest

# Update package repositories and install the g++ compiler
RUN apt-get update && apt-get install -y g++ make

# Set the working directory
WORKDIR /app

# Copy the contents of the current directory (Docker context) into the container
COPY . /app

# Build and run each of the exercises (ex00, ex01, ex02, ex03)
CMD for dir in ex*; do \
  if [ -d "$dir" ]; then \
    cd "$dir" && make && ./"$dir" && cd ..; \
  fi; \
done