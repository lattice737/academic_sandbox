# Keep in the root folder of the app
# Builds image and documents the app

# Always start with a FROM instruction
# Best practice is to use official images
# FROM: base image
FROM alpine

# Best practice is to list a maintainer (metadata)
LABEL maintainer="nedwardmartinez@gmail.com"

# Add software to the image
# RUN: execute command and create layer
RUN apk add --update nodejs npm

# Copy source code to the image
# COPY <source> <destination>
COPY . /src

# Set working directory (metadata)
WORKDIR /src

# Install dependencies
RUN npm install

# Expose port for app listening (metadata)
EXPOSE 8080

# Default app for image/container (metadata)
ENTRYPOINT ["node", "./app.js"]