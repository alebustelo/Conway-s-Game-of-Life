// FYI: Jenkins does not like apostrophes in job names
pipeline {
  agent any
  options {
    timestamps()
  }
  stages {
    stage('compile') {
      steps {
        sh 'make'
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
