FROM ubuntu:22.04

# Eviter les questions interactives pendant apt
ENV DEBIAN_FRONTEND=noninteractive

# Mise à jour + outils de base + libs X11 + build C
RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    cmake \
    gdb \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    libxrandr-dev \
    libpng-dev \
    libz-dev \
    pkg-config \
    vim \
    nano \
    && rm -rf /var/lib/apt/lists/*

# Mettre /bin/bash comme shell par défaut
SHELL ["/bin/bash", "-c"]