# To run, fork from: https://github.com/dockersamples/atsea-sample-shop-app
# Use command: docker image build -t multistage .

# Multiple FROM instructions, marking distinct build stages
# First two stages: four images with a lot of build machinery and a small bit of production code
# Last stage pulls a small base image and then only copies the previous stages' production code,
# leaving the bloated images behind and retaining only the production code needed at runtime

# Produces an image based on node:latest with a small, app-related piece of code needed at runtime
FROM node:latest AS storefront
WORKDIR /usr/src/atsea/app/react-app
COPY react-app
RUN npm install
RUN npm run build

# Produces an image based on maven:latest with another small, app-related piece of code
FROM maven:latest AS appserver
WORKDIR /usr/src/atsea
COPY pom.xml
RUN mvn -B -f pom.xml -s /usr/share/maven/ref/settings-docker.xml dependency:resolve
COPY . .
RUN mv -B -s /usr/share/maven/ref/settings-docker.xml package -DskipTests

# Copy instructions only copy the application code needed from the previous stage images
# storefront: build code
# appserver: jar file
FROM java:8-jdk-alpine AS production
RUN adduser -Dh /home/gordon gordon
WORKDIR /static
COPY --from=storefront /usr/src/atsea/app/react-app/build/ .
WORKDIR /app
COPY --from=appserver /usr/src/atsea/target/AtSea-0.0.1-SNAPSHOT.jar .
ENTRYPOINT ["java", "-jar", "/app/AtSea-0.0.1-SNAPSHOT.jar"]
CMD ["--spring.profiles.active=postgres"]