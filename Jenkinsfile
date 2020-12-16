// Copyright 2019 RADAR, Inc. - All Rights Reserved
// Proprietary and confidential

pipeline {
    agent {
        docker {
            registryUrl 'https://docker.inradar.net'
            registryCredentialsId 'radar-docker-registry'
            image 'docker.inradar.net/ubuntu-20.04-boost:0.2.0'
            label 'docker'
        }
    }

    environment {
        PREFIX = "${WORKSPACE}/installed"
    }

    stages {
        stage('Boost.Build Setup') {
            steps {
                sh '''
                echo "# DO NOT EDIT - generated by Dockerfile" > tmp-user-config.jam
                echo "using doxygen ;" >> tmp-user-config.jam
                '''
            }
        }
        stage('Documentation') {
            steps {
                sh 'bjam --user-config=tmp-user-config.jam --verbose-test documentation'

                recordIssues(tools: [doxygen()])

                publishHTML([allowMissing: false,
                             alwaysLinkToLastBuild: true,
                             keepAll: false,
                             reportDir: 'project/bb/libll/html/api',
                             reportFiles: 'index.html',
                             reportName: 'libll API Reference Documentation',
                             reportTitles: ''])

                publishHTML([allowMissing: false,
                             alwaysLinkToLastBuild: true,
                             keepAll: false,
                             reportDir: 'project/bb/libtl/html/api',
                             reportFiles: 'index.html',
                             reportName: 'libtl API Reference Documentation',
                             reportTitles: ''])
            }
        }
        stage('Build') {
            steps {
                sh 'bjam --user-config=tmp-user-config.jam --verbose-test project/bb/example variant=debug variant=release'

                recordIssues(tools: [gcc4()])
            }
        }
        stage('Test') {
            environment {
                BOOST_TEST_LOGGER = 'JUNIT'
            }

            steps {
                sh 'bjam --user-config=tmp-user-config.jam --verbose-test variant=debug variant=release'

                junit '*.xml'
            }
        }
        stage('Install') {
            steps {
                sh 'bjam --user-config=tmp-user-config.jam --verbose-test variant=release install --prefix=${PREFIX}'
            }
        }
    }
}
