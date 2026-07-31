# Dockerfile
FROM ubuntu:22.04

# Éviter les prompts interactifs
ENV DEBIAN_FRONTEND=noninteractive

# Mise à jour + outils de base + valgrind
RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y \
        build-essential \
        gdb \
        valgrind \
        cmake \
        git \
        pkg-config \
        clang \
        clang-format \
        ninja-build \
        file \
        sudo \
        curl \
        ca-certificates && \
    rm -rf /var/lib/apt/lists/*

# Créer un user non-root (conseillé pour dev containers)
RUN useradd -m vscode && \
    echo "vscode ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

USER vscode
WORKDIR /workspaces

# Par défaut, VS Code montera ton repo dans /workspaces/<nom-du-projet>
