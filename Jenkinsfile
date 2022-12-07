pipeline {
  agent any
  options {
    timestamps()
  }
  stages {
    stage('compile') {
      steps {
        //sh 'make'
        sh 'gcc -o gol.o main.c -I. -std=c99'
      }
      post {
        success {
          archiveArtifacts artifacts: '*.o', fingerprint: true
        }
      }
    }
    // Will run forever
    // stage('take for a spin') {
    //   steps {
    //     sh './gol'
    //   }
    // }
  }
}
