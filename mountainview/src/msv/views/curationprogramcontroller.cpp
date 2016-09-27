#include "curationprogramcontroller.h"
#include "mlcommon.h"

#include <QJsonDocument>

class CurationProgramControllerPrivate {
public:
    CurationProgramController *q;

    MVContext *m_context;
    QString m_log;
};

CurationProgramController::CurationProgramController(MVContext *mvcontext)
{
    d=new CurationProgramControllerPrivate;
    d->q=this;
    d->m_context=mvcontext;
}

CurationProgramController::~CurationProgramController()
{
    delete d;
}

QString CurationProgramController::log() const
{
    return d->m_log;
}

QString CurationProgramController::clusterNumbers()
{
    QList<int> list=d->m_context->clusterAttributesKeys();
    QJsonArray list2;
    for (int i=0; i<list.count(); i++) {
        list2.append(list[i]);
    }
    return QJsonDocument(list2).toJson();
}

double CurationProgramController::metric(int cluster_number, QString metric_name)
{
    QJsonObject attributes=d->m_context->clusterAttributes(cluster_number);
    return attributes["metrics"].toObject()[metric_name].toDouble();
}

void CurationProgramController::addTag(int cluster_number, QString tag_name)
{
    QSet<QString> tags=d->m_context->clusterTags(cluster_number);
    tags.insert(tag_name);
    d->m_context->setClusterTags(cluster_number,tags);
}

void CurationProgramController::removeTag(int cluster_number, QString tag_name)
{
    QSet<QString> tags=d->m_context->clusterTags(cluster_number);
    tags.remove(tag_name);
    d->m_context->setClusterTags(cluster_number,tags);
}

void CurationProgramController::log(const QString &message)
{
    d->m_log+=message+"\n";
}
