// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#include "kubernetes_owner_kind.h"

namespace collector {

namespace {
static constexpr char REPLICA_SET_KIND[] = "ReplicaSet";
static constexpr char DEPLOYMENT_KIND[] = "Deployment";
static constexpr char JOB_KIND[] = "Job";
static constexpr char CRONJOB_KIND[] = "CronJob";
static constexpr char NO_OWNER_KIND[] = "NoOwner";
static constexpr char OTHER_KIND[] = "Other";
} // namespace

KubernetesOwnerKind KubernetesOwnerKindFromString(const std::string &str)
{
  if (str == REPLICA_SET_KIND) {
    return KubernetesOwnerKind::ReplicaSet;
  }

  if (str == DEPLOYMENT_KIND) {
    return KubernetesOwnerKind::Deployment;
  }

  if (str == JOB_KIND) {
    return KubernetesOwnerKind::Job;
  }

  if (str == CRONJOB_KIND) {
    return KubernetesOwnerKind::CronJob;
  }

  if (str == NO_OWNER_KIND) {
    return KubernetesOwnerKind::NoOwner;
  }

  return KubernetesOwnerKind::Other;
}

const char *KubernetesOwnerKindToString(const KubernetesOwnerKind kind)
{
  switch (kind) {
  case KubernetesOwnerKind::ReplicaSet:
    return REPLICA_SET_KIND;
  case KubernetesOwnerKind::Deployment:
    return DEPLOYMENT_KIND;
  case KubernetesOwnerKind::Job:
    return JOB_KIND;
  case KubernetesOwnerKind::CronJob:
    return CRONJOB_KIND;
  case KubernetesOwnerKind::NoOwner:
    return NO_OWNER_KIND;

  default:
    return OTHER_KIND;
  }
}

bool KubernetesOwnerIsDeployment(const std::string &str)
{
  return str == DEPLOYMENT_KIND;
}

bool KubernetesOwnerIsReplicaSet(const std::string &str)
{
  return str == REPLICA_SET_KIND;
}

bool KubernetesOwnerIsJob(const std::string &str)
{
  return str == JOB_KIND;
}

bool KubernetesOwnerIsCronJob(const std::string &str)
{
  return str == CRONJOB_KIND;
}

bool KubernetesOwnerIsNoOwner(const std::string &str)
{
  return str == NO_OWNER_KIND;
}

} // namespace collector
