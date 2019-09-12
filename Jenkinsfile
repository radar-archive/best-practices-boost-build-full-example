// Copyright 2019 RADAR, Inc. - All Rights Reserved
// Proprietary and confidential

pipeline {
    agent {
        docker {
            registryUrl 'https://docker.inradar.net'
            registryCredentialsId 'radar-docker-registry'
            image 'docker.inradar.net/ubuntu-18.04-boost:0.1.9'
            args '-v /usr/local/share/ca-certificates/inradar-ca.crt:/usr/local/share/ca-certificates/inradar-ca.crt -v /etc/ssl/certs:/etc/ssl/certs -v /etc/ca-certificates.conf:/etc/ca-certificates.conf'
        }
    }
    stages {
        stage('Build') {
            steps {
                sh 'bjam --verbose-test -j 8 -a project/bb/example variant=debug variant=release'

                recordIssues(tools: [gcc4()])
            }
        }
        stage('Test') {
            steps {
                sh 'bjam --verbose-test -j 8 -a variant=debug variant=release'
            }
        }
    }
}
